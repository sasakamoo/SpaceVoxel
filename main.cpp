#include <Windows.h>
#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Shader.h"

float squareVertices[] = {
     0.5f,  0.5f, 0.0f, // Top Right    
     0.5f, -0.5f, 0.0f, // Bottom Right
    -0.5f,  0.5f, 0.0f, // Top Left
    -0.5f, -0.5f, 0.0f  // Bottom Left
};

unsigned int indices[] = {
    0, 1, 2,
    1, 2, 3
};

float triangle1[] = {
     0.0f, 1.0f, 0.0f,
     1.0f, 0.0f, 0.0f,
     0.0f, 0.0f, 0.0f
};

float triangle2[] = {
    -1.0f,  0.0f, 0.0f,
     0.0f,  0.0f, 0.0f,
     0.0f, -1.0f, 0.0f,
};

float triangle3[] = {
     0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, // Position then color values
    -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 
     0.0f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f
};

void error_callback(int error, const char* description) {
    std::cerr << "Error: " << description << std::endl;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

int main() {
    
    if (!glfwInit()) {
        std::cerr << "Error: Failed Initializing GLFW" << std::endl;
        return -1;
    }
 
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    glfwSetErrorCallback(error_callback);

    GLFWwindow* window = glfwCreateWindow(640, 480, "Learning GLFW", NULL, NULL);
    
    if (!window) {
        std::cerr << "Error: Creating Window" << std::endl;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Error: Failed Initializing GLAD" << std::endl;
    }

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    int numAttributes;
    glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &numAttributes);
    std::cout << "Maximum Number of Vertex Attributes Supported: " << numAttributes << std::endl;

    Shader shaderProgram1("./../vertexShader1.shader", "./../fragmentShader1.shader");
    Shader shaderProgram2("./../vertexShader2.shader", "./../fragmentShader2.shader");

    // Vertex Array & Buffer Objects
    unsigned int VAO, VBO, EBO, VAO1, VAO2, VBO1, VBO2, VAO3, VBO3;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glGenVertexArrays(1, &VAO1);
    glGenBuffers(1, &VBO1);
    glGenVertexArrays(1, &VAO2);
    glGenBuffers(1, &VBO2);
    glGenVertexArrays(1, &VAO3);
    glGenBuffers(1, &VBO3);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(squareVertices), squareVertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(VAO1);
    glBindBuffer(GL_ARRAY_BUFFER, VBO1);
    glBufferData(GL_ARRAY_BUFFER, sizeof(triangle1), triangle1, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(VAO2);
    glBindBuffer(GL_ARRAY_BUFFER, VBO2);
    glBufferData(GL_ARRAY_BUFFER, sizeof(triangle2), triangle2, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(VAO3);
    glBindBuffer(GL_ARRAY_BUFFER, VBO3);
    glBufferData(GL_ARRAY_BUFFER, sizeof(triangle3), triangle3, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6*sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6*sizeof(float), (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    while (!glfwWindowShouldClose(window)) {
        processInput(window);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        shaderProgram1.use();

        float timeValue = glfwGetTime();
        float redValue = (sin(timeValue + 0.3) / 2.0f) + 0.5f;
        float greenValue = (sin(timeValue + 0.1) / 2.0f) + 0.5f;
        float blueValue = (sin(timeValue) / 2.0f) + 0.5f;

        int vertexColorLocation = glGetUniformLocation(shaderProgram1.ID, "color");
        glUniform4f(vertexColorLocation, redValue, greenValue, blueValue, 1.0f);

        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glBindVertexArray(VAO1);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glBindVertexArray(VAO2);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glBindVertexArray(0);
        
        shaderProgram2.use();

        glBindVertexArray(VAO3);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    glDeleteVertexArrays(1, &VAO1);
    glDeleteBuffers(1, &VBO1);
    glDeleteVertexArrays(1, &VAO2);
    glDeleteBuffers(1, &VBO2);

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}