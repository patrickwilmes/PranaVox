/*
* Copyright (c) 2025, Patrick Wilmes <p.wilmes89@gmail.com>
* All rights reserved.
*
* SPDX-License-Identifier: BSD-2-Clause
*/
#include "Renderer.h"
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Window.h"

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
// todo - move all the logic in here into a dedicated class, as it's not a rendering concern
void hello_renderer() {
    glfwInit();
    const Window window(800, 600, "Test");
    window.make_current_context();
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return;
    }
    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window.get_window(), framebuffer_size_callback);
    while (!window.should_close()) {
        window.swap_buffers();
        glfwPollEvents();
    }
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
}
