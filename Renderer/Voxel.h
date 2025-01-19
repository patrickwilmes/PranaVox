/*
* Copyright (c) 2025, Patrick Wilmes <p.wilmes89@gmail.com>
* All rights reserved.
*
* SPDX-License-Identifier: BSD-2-Clause
*/
#ifndef VOXEL_H
#define VOXEL_H

#include <vector>
#include <glad/glad.h>

namespace Graphics {
    class Voxel {
    public:
        Voxel();

        ~Voxel();

        void draw() const;

    private:
        std::vector<float> vertices;
        GLuint VBO{}, VAO{};
    };
}

#endif //VOXEL_H
