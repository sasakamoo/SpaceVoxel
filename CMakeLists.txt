cmake_minimum_required(VERSION 3.6)
set(CMAKE_CXX_STANDARD 17)
project(myapp)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

set(GLAD_INCLUDE C:/Users/Moose/Documents/Dev/glad/include)
set(GLAD_SRC C:/Users/Moose/Documents/Dev/glad/src/glad.c)

include_directories(./Include)
include_directories(${GLAD_INCLUDE})
include_directories(C:/Users/Moose/Documents/Dev/stb)
add_subdirectory(C:/Users/Moose/Documents/Dev/glfw-3.3.8 ./glfw)
add_subdirectory(C:/Users/Moose/Documents/Dev/glm ./glm)
set(SOURCE_FILES ./Source/main.cpp ./Source/Shader.cpp ./Source/Primitives.cpp ./Source/Camera.cpp ./Source/Input.cpp ${GLAD_SRC})

add_executable(myapp ${SOURCE_FILES})

find_package(OpenGL REQUIRED)
target_link_libraries(myapp glfw)
target_link_libraries(myapp glm)
target_link_libraries(myapp OpenGL::GL)
target_link_libraries(myapp stdc++)