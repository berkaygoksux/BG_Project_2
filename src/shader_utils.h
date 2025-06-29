#ifndef SHADER_UTILS_H
#define SHADER_UTILS_H

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

GLuint createShaderProgram(const char* vertexPath, const char* fragmentPath) {
    // Vertex shader kodunu oku
    std::ifstream vFile(vertexPath);
    std::ifstream fFile(fragmentPath);
    if (!vFile || !fFile) {
        std::cerr << "Shader dosyası açılamadı: " << vertexPath << " veya " << fragmentPath << std::endl;
        return 0;
    }
    std::stringstream vStream, fStream;
    vStream << vFile.rdbuf();
    fStream << fFile.rdbuf();
    std::string vertexCode = vStream.str();
    std::string fragmentCode = fStream.str();
    const char* vShaderCode = vertexCode.c_str();
    const char* fShaderCode = fragmentCode.c_str();

    GLuint vertex, fragment;
    GLint success;
    char infoLog[512];

    // Vertex shader oluştur ve derle
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vShaderCode, NULL);
    glCompileShader(vertex);
    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertex, 512, NULL, infoLog);
        std::cerr << "Vertex Shader derleme hatası:\n" << infoLog << std::endl;
    }

    // Fragment shader oluştur ve derle
    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fShaderCode, NULL);
    glCompileShader(fragment);
    glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragment, 512, NULL, infoLog);
        std::cerr << "Fragment Shader derleme hatası:\n" << infoLog << std::endl;
    }

    // Shader programı oluştur ve linkle
    GLuint program = glCreateProgram();
    glAttachShader(program, vertex);
    glAttachShader(program, fragment);
    glLinkProgram(program);
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(program, 512, NULL, infoLog);
        std::cerr << "Shader Program link hatası:\n" << infoLog << std::endl;
    }

    // Shader nesnelerini sil
    glDeleteShader(vertex);
    glDeleteShader(fragment);

    return program;
}

#endif
