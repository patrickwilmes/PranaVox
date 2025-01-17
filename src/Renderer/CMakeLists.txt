set(SOURCE_FILES
        ${CMAKE_SOURCE_DIR}/libs/glad/src/glad.c
        ${CMAKE_SOURCE_DIR}/libs/glad/include/glad/glad.h
        Renderer.cpp
        Renderer.h
        Window.cpp
        Window.h
        Shader.cpp
        Shader.h
)

include_directories(${CMAKE_SOURCE_DIR}/libs/glfw-3.3.8/include)
include_directories(${CMAKE_SOURCE_DIR}/libs/glad/include)

add_library(TriAxisLib ${SOURCE_FILES})
target_link_libraries(TriAxisLib PRIVATE glfw AK)
