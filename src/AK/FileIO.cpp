/*
* Copyright (c) 2025, Patrick Wilmes <p.wilmes89@gmail.com>
* All rights reserved.
*
* SPDX-License-Identifier: BSD-2-Clause
*/
#include "FileIO.h"
#include <iostream>
#include <fstream>

char *AK::IO::read_file_to_c_string(const char *filePath) {
    std::ifstream file(filePath, std::ios::in | std::ios::binary);

    if (!file) {
        std::cerr << "Failed to open file " << filePath << std::endl;
        return nullptr;
    }

    file.seekg(0, std::ios::end);
    const std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);

    if (size <= 0) {
        std::cerr << "Failed to read file " << filePath << std::endl;
        return nullptr;
    }

    char *buffer = new char[size + 1];
    if (file.read(buffer, size)) {
        buffer[size] = '\0';
    } else {
        std::cerr << "Failed to read file " << filePath << std::endl;
        delete[] buffer;
        return nullptr;
    }
    return buffer;
}
