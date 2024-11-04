#include "Input.h"
#include <iostream>

Input::Input() {
    direction = glm::vec3(0.0f, 0.0f, 0.0f);
}

void Input::update(GLFWwindow* window) {
    direction = glm::vec3(0.0f, 0.0f, 0.0f);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        direction.y += 1;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) 
        direction.y -= 1;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        direction.x += 1;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        direction.x -= 1;

    if (direction != glm::vec3(0.0f, 0.0f, 0.0f))
        direction = glm::normalize(direction);
}

const glm::vec3 Input::getDirection() const {
    return direction;
}

void Input::wireframeCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    static bool wireframeMode = false;
    if (key == GLFW_KEY_BACKSLASH && action == GLFW_PRESS) {
        wireframeMode = !wireframeMode;
        if (wireframeMode)
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        else
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
}