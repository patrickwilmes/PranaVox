/*
* Copyright (c) 2025, Patrick Wilmes <p.wilmes89@gmail.com>
* All rights reserved.
*
* SPDX-License-Identifier: BSD-2-Clause
*/
#ifndef FILEUTILS_H
#define FILEUTILS_H

namespace AK::IO {
    char *read_file_to_c_string(const char *filePath);
}


#endif //FILEUTILS_H
