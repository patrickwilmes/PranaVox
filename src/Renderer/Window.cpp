/*
* Copyright (c) 2025, Patrick Wilmes <p.wilmes89@gmail.com>
* All rights reserved.
*
* SPDX-License-Identifier: BSD-2-Clause
*/
#include "Window.h"
#include <iostream>

Window::Window(const int width, const int height, const char *title) {
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

Window::~Window() {
    glfwTerminate();
}

void Window::swap_buffers() const {
    glfwSwapBuffers(m_window);
}

bool Window::should_close() const {
    return glfwWindowShouldClose(m_window);
}

void Window::make_current_context() const {
    glfwMakeContextCurrent(m_window);
}
