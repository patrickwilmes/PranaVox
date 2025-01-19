/*
* Copyright (c) 2025, Patrick Wilmes <p.wilmes89@gmail.com>
* All rights reserved.
*
* SPDX-License-Identifier: BSD-2-Clause
*/
#ifndef APPLICATION_H
#define APPLICATION_H

#include "Window.h"
#include "Renderer.h"

namespace Graphics {
    class App final {
    public:
        App();

        ~App();

        void run() const;

    private:
        Window *m_window;
        Renderer *m_renderer;
    };
}

#endif //APPLICATION_H
