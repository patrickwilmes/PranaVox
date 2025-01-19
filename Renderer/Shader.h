/*
* Copyright (c) 2025, Patrick Wilmes <p.wilmes89@gmail.com>
* All rights reserved.
*
* SPDX-License-Identifier: BSD-2-Clause
*/

#ifndef SHADER_H
#define SHADER_H
#include <string>

class Shader final {
public:
    unsigned int ID{};

    Shader(const char* vertexPath, const char* fragmentPath);
    void use() const;
    void set_bool(const std::string& name, bool value) const;
    void set_int(const std::string& name, int value) const;
    void set_float(const std::string& name, float value) const;

private:
    static void check_compile_errors(unsigned int shader, const std::string &type);
};

#endif //SHADER_H
