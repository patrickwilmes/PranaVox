/*
* Copyright (c) 2025, Patrick Wilmes <p.wilmes89@gmail.com>
* All rights reserved.
*
* SPDX-License-Identifier: BSD-2-Clause
*/
#ifndef WINDOW_H
#define WINDOW_H
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Graphics {
    class Window final {
    public:
        Window(int width, int height, const char *title);

        ~Window();

        void swap_buffers() const;

        [[nodiscard]] bool should_close() const;

        void make_current_context() const;

        // todo - remove this getter and make the framebuffer_size_callback happening within
        [[nodiscard]] GLFWwindow *get_window() const { return m_window; }

        void make_visible() const;

    private:
        GLFWwindow *m_window = nullptr;

        static void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
            glViewport(0, 0, width, height);
        }
    };
}
#endif //WINDOW_H
