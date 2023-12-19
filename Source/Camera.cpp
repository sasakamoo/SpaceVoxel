#include "Camera.h"

int Camera::screenWidth = 0;
int Camera::screenHeight = 0;
bool Camera::updateViewport = false;

Camera::Camera(int width, int height) {
    screenWidth = width;
    screenHeight = height;
    updateViewport = false;
    view = glm::mat4(1.0f);
    glm::vec3 cameraPosition = glm::vec3(0.0f, 0.0f, 3.0f);
    glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);

    view = glm::lookAt(cameraPosition, cameraTarget, up);
    
    projection = glm::mat4(1.0f);
    projection = glm::perspective(glm::radians(45.0f), (float)screenWidth/(float)screenHeight, 0.1f, 100.0f);
}

const glm::mat4 Camera::getView() const {
    return view;
}

const glm::mat4 Camera::getProjection() const {
    return projection;
}

void Camera::update() {
    if (updateViewport) {
        projection = glm::perspective(glm::radians(45.0f), (float)screenWidth/(float)screenHeight, 0.1f, 100.0f);
    }

    updateViewport = false;
}

void Camera::framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    screenWidth = width;
    screenHeight = height;
    updateViewport = true;
    glViewport(0, 0, width, height);
}