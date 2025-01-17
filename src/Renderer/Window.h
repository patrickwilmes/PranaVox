/*
* Copyright (c) 2025, Patrick Wilmes <p.wilmes89@gmail.com>
* All rights reserved.
*
* SPDX-License-Identifier: BSD-2-Clause
*/
#ifndef WINDOW_H
#define WINDOW_H
#include <GLFW/glfw3.h>

class Window final{
public:
    Window(int width, int height, const char *title);
    ~Window();
    void swap_buffers() const;
    [[nodiscard]] bool should_close() const;
    void make_current_context() const;
    // todo - remove this getter and make the framebuffer_size_callback happening within
    [[nodiscard]] GLFWwindow *get_window() const { return m_window; }
private:
    GLFWwindow *m_window = nullptr;
};

#endif //WINDOW_H
