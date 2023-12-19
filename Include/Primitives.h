#ifndef PRIMITIVES_H
#define PRIMITIVES_H

#include <iostream>
#include <vector>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
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
    glm::mat4 transform;
    std::vector<glm::vec3> vertices;
    unsigned int VAO, VBO;

    float movespeed = 10.0f;

public:
    Circle();
    ~Circle();

    void update(const glm::vec3 direction);

    const glm::mat4 getTransform() const;

    void draw();
};

#endif