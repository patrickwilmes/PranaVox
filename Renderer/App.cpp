/*
* Copyright (c) 2025, Patrick Wilmes <p.wilmes89@gmail.com>
* All rights reserved.
*
* SPDX-License-Identifier: BSD-2-Clause
*/
#include "App.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Window.h"
#include "Shader.h"
#include "Voxel.h"

void processInput(GLFWwindow *window);

Graphics::App::App() {
    glfwInit();
    m_window = new Window(800, 600, "PranaVox");
    m_window->make_current_context();
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return;
    }

    m_window->make_visible();
    m_renderer = new Renderer();
}

void Graphics::App::run() const {
    const Shader shader("Shader/shader.vs", "Shader/shader.fs");
    const Voxel voxel;

    while (!m_window->should_close()) {
        processInput(m_window->get_window());

        m_renderer->clear();

        shader.use();
        voxel.draw();

        m_window->swap_buffers();
        glfwPollEvents();
    }
}

Graphics::App::~App() {
    delete m_renderer;
    delete m_window;
}

void processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}
