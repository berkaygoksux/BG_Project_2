#include <glad/glad.h>
#include "scene.h"
#include <GLFW/glfw3.h>

// Her vertex için: pozisyon(3) + normal(3)
float cubeVertices[] = {
    // back face
   -0.5f, -0.5f, -0.5f,   0.0f,  0.0f, -1.0f,
    0.5f, -0.5f, -0.5f,   0.0f,  0.0f, -1.0f,
    0.5f,  0.5f, -0.5f,   0.0f,  0.0f, -1.0f,
    0.5f,  0.5f, -0.5f,   0.0f,  0.0f, -1.0f,
   -0.5f,  0.5f, -0.5f,   0.0f,  0.0f, -1.0f,
   -0.5f, -0.5f, -0.5f,   0.0f,  0.0f, -1.0f,

   // front face
   -0.5f, -0.5f,  0.5f,   0.0f,  0.0f, 1.0f,
    0.5f, -0.5f,  0.5f,   0.0f,  0.0f, 1.0f,
    0.5f,  0.5f,  0.5f,   0.0f,  0.0f, 1.0f,
    0.5f,  0.5f,  0.5f,   0.0f,  0.0f, 1.0f,
   -0.5f,  0.5f,  0.5f,   0.0f,  0.0f, 1.0f,
   -0.5f, -0.5f,  0.5f,   0.0f,  0.0f, 1.0f,

   // left face
   -0.5f,  0.5f,  0.5f,  -1.0f,  0.0f,  0.0f,
   -0.5f,  0.5f, -0.5f,  -1.0f,  0.0f,  0.0f,
   -0.5f, -0.5f, -0.5f,  -1.0f,  0.0f,  0.0f,
   -0.5f, -0.5f, -0.5f,  -1.0f,  0.0f,  0.0f,
   -0.5f, -0.5f,  0.5f,  -1.0f,  0.0f,  0.0f,
   -0.5f,  0.5f,  0.5f,  -1.0f,  0.0f,  0.0f,

   // right face
    0.5f,  0.5f,  0.5f,   1.0f,  0.0f,  0.0f,
    0.5f,  0.5f, -0.5f,   1.0f,  0.0f,  0.0f,
    0.5f, -0.5f, -0.5f,   1.0f,  0.0f,  0.0f,
    0.5f, -0.5f, -0.5f,   1.0f,  0.0f,  0.0f,
    0.5f, -0.5f,  0.5f,   1.0f,  0.0f,  0.0f,
    0.5f,  0.5f,  0.5f,   1.0f,  0.0f,  0.0f,

   // bottom face
   -0.5f, -0.5f, -0.5f,   0.0f, -1.0f,  0.0f,
    0.5f, -0.5f, -0.5f,   0.0f, -1.0f,  0.0f,
    0.5f, -0.5f,  0.5f,   0.0f, -1.0f,  0.0f,
    0.5f, -0.5f,  0.5f,   0.0f, -1.0f,  0.0f,
   -0.5f, -0.5f,  0.5f,   0.0f, -1.0f,  0.0f,
   -0.5f, -0.5f, -0.5f,   0.0f, -1.0f,  0.0f,

   // top face
   -0.5f,  0.5f, -0.5f,   0.0f, 1.0f,  0.0f,
    0.5f,  0.5f, -0.5f,   0.0f, 1.0f,  0.0f,
    0.5f,  0.5f,  0.5f,   0.0f, 1.0f,  0.0f,
    0.5f,  0.5f,  0.5f,   0.0f, 1.0f,  0.0f,
   -0.5f,  0.5f,  0.5f,   0.0f, 1.0f,  0.0f,
   -0.5f,  0.5f, -0.5f,   0.0f, 1.0f,  0.0f,
};

const size_t cubeVertices_size = sizeof(cubeVertices);

unsigned int cubeVAO = 0, cubeVBO = 0;

void initSceneObjects() {
    glGenVertexArrays(1, &cubeVAO);
    glGenBuffers(1, &cubeVBO);

    glBindVertexArray(cubeVAO);

    glBindBuffer(GL_ARRAY_BUFFER, cubeVBO);
    glBufferData(GL_ARRAY_BUFFER, cubeVertices_size, cubeVertices, GL_STATIC_DRAW);

    // Pozisyon
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Normal
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
}

void renderSceneObjects() {
    glBindVertexArray(cubeVAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);
}
