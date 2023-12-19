#include "Input.h"

Input::Input() {
    direction = glm::vec3(0.0f, 0.0f, 0.0f);
}

void Input::update(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        direction.y += 1;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        direction.y -= 1;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        direction.x += 1;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        direction.x -= 1;

    direction = glm::normalize(direction);
}

const glm::vec3 Input::getDirection() const {
    return direction;
}