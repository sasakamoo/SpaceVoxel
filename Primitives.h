#ifndef PRIMITIVES_H
#define PRIMITIVES_H

#include <Windows.h>
#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

class Triangle {
private:
    float vertices[9];
    unsigned int VAO, VBO;

public:
    Triangle(glm::vec3 p1, glm::vec3 p2, glm::vec3 p3);
    ~Triangle();

    void Draw();
};

class Rectangle {
public: 
    Rectangle();
    ~Rectangle();

    void Draw();
};

class Square {
public:
    Square();
    ~Square();

    void Draw();
};

#endif