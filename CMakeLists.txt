cmake_minimum_required(VERSION 3.10)
project(sinifta_esya_arama)

set(CMAKE_CXX_STANDARD 17)

# GLAD include
include_directories(${PROJECT_SOURCE_DIR}/libs/glad/include)
include_directories(${PROJECT_SOURCE_DIR}/libs/stb)


# GLFW ve OpenGL bul (macOS Homebrew yüklü kabulüyle)
find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

# Kaynak dosyalar (GLAD kaynak kodu ile birlikte)
file(GLOB SRC_FILES src/*.cpp libs/glad/src/*.c)

add_executable(${PROJECT_NAME} ${SRC_FILES})

target_link_libraries(${PROJECT_NAME} glfw OpenGL::GL)
