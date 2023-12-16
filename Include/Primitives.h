#ifndef PRIMITIVES_H
#define PRIMITIVES_H

#include <iostream>
#include <vector>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>

class Triangle {
private:
    std::vector<glm::vec3> vertices;
    unsigned int VAO, VBO;

public:
    Triangle(glm::vec3 p1, glm::vec3 p2, glm::vec3 p3);
    ~Triangle();

    void draw();
};

class Rect {
private:
    std::vector<glm::vec3> vertices;
    int indices[6];
    unsigned int VAO, VBO, EBO;

public: 
    Rect(glm::vec3 p1, glm::vec3 p2, glm::vec3 p3, glm::vec3 p4);
    ~Rect();

    void draw();
};

class Circle {
private:
    std::vector<glm::vec3> vertices;
    unsigned int VAO, VBO;

public:
    Circle();
    ~Circle();

    void draw();
};

#endif