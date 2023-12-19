#include "Input.h"
#include <iostream>

Input::Input() {
    direction = glm::vec3(0.0f, 0.0f, 0.0f);
}

void Input::update(GLFWwindow* window) {
    direction = glm::vec3(0.0f, 0.0f, 0.0f);
    bool directionUpdated = false;
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        direction.y += 1;
        directionUpdated = true;
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        direction.y -= 1;
        directionUpdated = true;
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        direction.x += 1;
        directionUpdated = true;
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        direction.x -= 1;
        directionUpdated = true;
    }

    if (directionUpdated)
        direction = glm::normalize(direction);
}

const glm::vec3 Input::getDirection() const {
    return direction;
}