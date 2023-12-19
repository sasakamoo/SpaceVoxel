#ifndef CAMERA_H
#define CAMERA_H

#include "GLFW/glfw3.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {
private:
    glm::vec3 position;
    glm::vec3 target;
    glm::vec3 up;

    glm::mat4 view;
    glm::mat4 projection;

    static int screenWidth;
    static int screenHeight;
    static bool updateViewport;
public:
    Camera(int screenWidth, int screenHeight);
    ~Camera() = default;

    const glm::mat4 getView() const;
    const glm::mat4 getProjection() const;

    void update();

    static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
};

#endif