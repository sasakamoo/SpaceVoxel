cmake_minimum_required(VERSION 3.6)
set(CMAKE_CXX_STANDARD 17)
project(myapp)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

set(GLAD_INCLUDE C:/Users/Moose/Documents/Dev/glad/include)
set(GLAD_SRC C:/Users/Moose/Documents/Dev/glad/src/glad.c)

include_directories(${GLAD_INCLUDE})
add_subdirectory(C:/Users/Moose/Documents/Dev/glfw-3.3.8 ./glfw)

set(SOURCE_FILES main.cpp ${GLAD_SRC})

add_executable(myapp ${SOURCE_FILES})

find_package(OpenGL REQUIRED)
target_link_libraries(myapp glfw)
target_link_libraries(myapp OpenGL::GL)
target_link_libraries(myapp stdc++)