#include "Primitives.h"

Triangle::Triangle(glm::vec3 p1, glm::vec3 p2, glm::vec3 p3) {
    vertices[0] = p1.x; vertices[1] = p1.y; vertices[2] = p1.z;
    vertices[3] = p2.x; vertices[4] = p2.y; vertices[5] = p2.z;
    vertices[6] = p3.x; vertices[7] = p3.y; vertices[8] = p3.z;

    // Generate VAO and VBO
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    // Bind VAO and VBO
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Unbind Buffer
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

Triangle::~Triangle() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

void Triangle::Draw() {
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}