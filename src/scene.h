#ifndef SCENE_H
#define SCENE_H

#include <cstddef>

extern float cubeVertices[];
extern const size_t cubeVertices_size;
extern unsigned int cubeVAO, cubeVBO;

void initSceneObjects();
void renderSceneObjects();

#endif

