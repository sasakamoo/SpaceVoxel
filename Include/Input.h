#ifndef INPUT_H
#define INPUT_H

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Input {
private:
    glm::vec3 direction;

public:
    Input();
    ~Input() = default;

    void update(GLFWwindow* window);

    const glm::vec3 getDirection() const;
};

#endif