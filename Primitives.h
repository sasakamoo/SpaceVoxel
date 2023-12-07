#ifndef PRIMITIVES_H
#define PRIMITIVES_H

#include <Windows.h>
#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>

class Triangle {
private:
    float vertices[9];
    unsigned int VAO, VBO;

public:
    Triangle(glm::vec3 p1, glm::vec3 p2, glm::vec3 p3);
    ~Triangle();

    void draw();
};

class Rectangle {
private:
    float vertices[12];
    int indices[6];
    unsigned int VAO, VBO, EBO;

public: 
    Rectangle(glm::vec3 p1, glm::vec3 p2, glm::vec3 p3, glm::vec3 p4);
    ~Rectangle();

    void draw();
};

class Circle {
private:
    float vertices[3*10];
    unsigned int VAO, VBO;

public:
    Circle();
    ~Circle();

    void draw();
};

#endif