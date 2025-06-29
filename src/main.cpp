#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "shader_utils.h"
#include "scene.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_inverse.hpp>  // ray dönüşümü için

int screenWidth = 800, screenHeight = 600;

glm::vec3 cameraPos   = glm::vec3(0.0f, 0.0f, 3.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp    = glm::vec3(0.0f, 1.0f, 0.0f);

float deltaTime = 0.0f;
float lastFrame = 0.0f;

glm::mat4 projection;
glm::mat4 view;

enum SelectedObject { NONE, TABLE, DRAWER, ITEM };
SelectedObject selectedObject = NONE;

// Nesnelerin pozisyon ve dönüş değerleri
glm::vec3 tablePos = glm::vec3(0.0f, -0.5f, 0.0f);
glm::vec3 drawerPos = glm::vec3(0.0f, -0.8f, 0.0f);
glm::vec3 itemPos = glm::vec3(0.0f, -0.2f, 0.0f);

float tableRotation = 0.0f;
float drawerRotation = 0.0f;
float itemRotation = 0.0f;

void framebuffer_size_callback(GLFWwindow* window, int w, int h) {
    glViewport(0, 0, w, h);
}

void processInput(GLFWwindow *window) {
    float currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;
    float cameraSpeed = 2.5f * deltaTime;
    float objectMoveSpeed = 1.5f * deltaTime;
    float objectRotateSpeed = 90.0f * deltaTime; // derece/sn

    // Kamera hareketleri (WASD)
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        cameraPos += cameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        cameraPos -= cameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;

    // Nesne hareket/dönüş (seçili nesne için)
    if (selectedObject != NONE) {
        if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
            switch (selectedObject) {
                case TABLE: tablePos.z -= objectMoveSpeed; break;
                case DRAWER: drawerPos.z -= objectMoveSpeed; break;
                case ITEM: itemPos.z -= objectMoveSpeed; break;
                default: break;
            }
        }
        if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
            switch (selectedObject) {
                case TABLE: tablePos.z += objectMoveSpeed; break;
                case DRAWER: drawerPos.z += objectMoveSpeed; break;
                case ITEM: itemPos.z += objectMoveSpeed; break;
                default: break;
            }
        }
        if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
            switch (selectedObject) {
                case TABLE: tableRotation += objectRotateSpeed; break;
                case DRAWER: drawerRotation += objectRotateSpeed; break;
                case ITEM: itemRotation += objectRotateSpeed; break;
                default: break;
            }
        }
        if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
            switch (selectedObject) {
                case TABLE: tableRotation -= objectRotateSpeed; break;
                case DRAWER: drawerRotation -= objectRotateSpeed; break;
                case ITEM: itemRotation -= objectRotateSpeed; break;
                default: break;
            }
        }
    }
}

glm::vec3 screenPosToWorldRay(double mouseX, double mouseY, int screenWidth, int screenHeight,
                              const glm::mat4& projection, const glm::mat4& view) {
    float x = (2.0f * mouseX) / screenWidth - 1.0f;
    float y = 1.0f - (2.0f * mouseY) / screenHeight;
    float z = 1.0f;

    glm::vec3 rayNds = glm::vec3(x, y, z);
    glm::vec4 rayClip = glm::vec4(rayNds.x, rayNds.y, -1.0f, 1.0f);

    glm::vec4 rayEye = glm::inverse(projection) * rayClip;
    rayEye = glm::vec4(rayEye.x, rayEye.y, -1.0f, 0.0f);

    glm::vec3 rayWorld = glm::vec3(glm::inverse(view) * rayEye);
    rayWorld = glm::normalize(rayWorld);

    return rayWorld;
}

bool rayIntersectsAABB(glm::vec3 rayOrigin, glm::vec3 rayDir, 
                       glm::vec3 boxMin, glm::vec3 boxMax, float& t) {
    float tmin = (boxMin.x - rayOrigin.x) / rayDir.x;
    float tmax = (boxMax.x - rayOrigin.x) / rayDir.x;

    if (tmin > tmax) std::swap(tmin, tmax);

    float tymin = (boxMin.y - rayOrigin.y) / rayDir.y;
    float tymax = (boxMax.y - rayOrigin.y) / rayDir.y;

    if (tymin > tymax) std::swap(tymin, tymax);

    if ((tmin > tymax) || (tymin > tmax))
        return false;

    if (tymin > tmin)
        tmin = tymin;
    
    if (tymax < tmax)
        tmax = tymax;

    float tzmin = (boxMin.z - rayOrigin.z) / rayDir.z;
    float tzmax = (boxMax.z - rayOrigin.z) / rayDir.z;

    if (tzmin > tzmax) std::swap(tzmin, tzmax);

    if ((tmin > tzmax) || (tzmin > tmax))
        return false;

    if (tzmin > tmin)
        tmin = tzmin;

    if (tzmax < tmax)
        tmax = tzmax;

    t = tmin;

    if (t < 0) {
        t = tmax;
        if (t < 0) return false;
    }

    return true;
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
    if(button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);

        glm::vec3 rayOrigin = cameraPos;
        glm::vec3 rayDir = screenPosToWorldRay(xpos, ypos, screenWidth, screenHeight, projection, view);

        float closestT = 1e30f;
        bool hit = false;
        std::string hitObject = "";

        glm::vec3 masaMin = glm::vec3(-0.75f, -0.65f, -0.5f);
        glm::vec3 masaMax = glm::vec3(0.75f, -0.35f, 0.5f);
        float t;
        if (rayIntersectsAABB(rayOrigin, rayDir, masaMin, masaMax, t)) {
            if (t < closestT) {
                closestT = t;
                hit = true;
                hitObject = "Masa";
            }
        }

        glm::vec3 cekmeceMin = glm::vec3(-0.25f, -1.0f, -0.25f);
        glm::vec3 cekmeceMax = glm::vec3(0.25f, -0.6f, 0.25f);
        if (rayIntersectsAABB(rayOrigin, rayDir, cekmeceMin, cekmeceMax, t)) {
            if (t < closestT) {
                closestT = t;
                hit = true;
                hitObject = "Çekmece";
            }
        }

        glm::vec3 esyaMin = glm::vec3(-0.1f, -0.3f, -0.1f);
        glm::vec3 esyaMax = glm::vec3(0.1f, -0.1f, 0.1f);
        if (rayIntersectsAABB(rayOrigin, rayDir, esyaMin, esyaMax, t)) {
            if (t < closestT) {
                closestT = t;
                hit = true;
                hitObject = "Eşya";
            }
        }

        if (hit) {
            std::cout << "Seçilen nesne: " << hitObject << std::endl;
            if (hitObject == "Masa") selectedObject = TABLE;
            else if (hitObject == "Çekmece") selectedObject = DRAWER;
            else if (hitObject == "Eşya") selectedObject = ITEM;
        } else {
            std::cout << "Hiçbir nesne seçilmedi." << std::endl;
            selectedObject = NONE;
        }
    }
}

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* win = glfwCreateWindow(screenWidth, screenHeight, "Sinifta Esya Arama", NULL, NULL);
    if (!win) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(win);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    glfwSetFramebufferSizeCallback(win, framebuffer_size_callback);
    glfwSetMouseButtonCallback(win, mouse_button_callback);

    glEnable(GL_DEPTH_TEST);

    GLuint shader = createShaderProgram("shaders/default.vert", "shaders/default.frag");
    if (shader == 0) {
        std::cerr << "Shader program oluşturulamadı! Program sonlandırılıyor.\n";
        glfwTerminate();
        return -1;
    }
    glUseProgram(shader);

    GLint projLoc = glGetUniformLocation(shader, "projection");
    GLint viewLoc = glGetUniformLocation(shader, "view");
    GLint modelLoc = glGetUniformLocation(shader, "model");
    GLint colorLoc = glGetUniformLocation(shader, "objectColor");
    GLint lightDirLoc = glGetUniformLocation(shader, "lightDir");
    GLint lightColorLoc = glGetUniformLocation(shader, "lightColor");

    initSceneObjects();

    glBindVertexArray(cubeVAO);
    glBindBuffer(GL_ARRAY_BUFFER, cubeVBO);

    glBufferData(GL_ARRAY_BUFFER, cubeVertices_size, cubeVertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    projection = glm::perspective(glm::radians(45.0f), (float)screenWidth / screenHeight, 0.1f, 100.0f);

    while (!glfwWindowShouldClose(win)) {
        processInput(win);

        glClearColor(0.7f, 0.7f, 0.7f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);

        glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

        glm::vec3 lightDir = glm::vec3(-0.2f, -1.0f, -0.3f);
        glm::vec3 lightColor = glm::vec3(1.0f);

        glUniform3fv(lightDirLoc, 1, glm::value_ptr(lightDir));
        glUniform3fv(lightColorLoc, 1, glm::value_ptr(lightColor));

        glBindVertexArray(cubeVAO);

        // Masa
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, tablePos);
        model = glm::rotate(model, glm::radians(tableRotation), glm::vec3(0.0f, 1.0f, 0.0f));
        model = glm::scale(model, glm::vec3(1.5f, 0.3f, 1.0f));
        if(selectedObject == TABLE)
            glUniform3f(colorLoc, 1.0f, 0.4f, 0.4f);
        else
            glUniform3f(colorLoc, 0.80f, 0.70f, 0.55f);
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        renderSceneObjects();

        // Çekmece
        model = glm::mat4(1.0f);
        model = glm::translate(model, drawerPos);
        model = glm::rotate(model, glm::radians(drawerRotation), glm::vec3(0.0f, 1.0f, 0.0f));
        model = glm::scale(model, glm::vec3(0.5f, 0.2f, 0.5f));
        if(selectedObject == DRAWER)
            glUniform3f(colorLoc, 1.0f, 0.4f, 0.4f);
        else
            glUniform3f(colorLoc, 0.65f, 0.50f, 0.35f);
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        renderSceneObjects();

        // Eşya
        model = glm::mat4(1.0f);
        model = glm::translate(model, itemPos);
        model = glm::rotate(model, glm::radians(itemRotation), glm::vec3(0.0f, 1.0f, 0.0f));
        model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));
        if(selectedObject == ITEM)
            glUniform3f(colorLoc, 1.0f, 0.4f, 0.4f);
        else
            glUniform3f(colorLoc, 0.95f, 0.90f, 0.60f);
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        renderSceneObjects();

        glfwSwapBuffers(win);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
