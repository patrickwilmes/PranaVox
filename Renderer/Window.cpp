/*
* Copyright (c) 2025, Patrick Wilmes <p.wilmes89@gmail.com>
* All rights reserved.
*
* SPDX-License-Identifier: BSD-2-Clause
*/
#include "Window.h"
#include <iostream>

Graphics::Window::Window(const int width, const int height, const char *title) {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    m_window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (m_window == nullptr) {
        // todo - throw an exception after glfwTerminate instead of stdout
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return;
    }
}

Graphics::Window::~Window() {
    glfwTerminate();
}

void Graphics::Window::swap_buffers() const {
    glfwSwapBuffers(m_window);
}

bool Graphics::Window::should_close() const {
    return glfwWindowShouldClose(m_window);
}

void Graphics::Window::make_visible() const {
    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(m_window, framebuffer_size_callback);
}

void Graphics::Window::make_current_context() const {
    glfwMakeContextCurrent(m_window);
}
