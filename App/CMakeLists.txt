add_subdirectory(libs/glfw-3.4)

include_directories(libs/glfw-3.3.8/include)
include_directories(libs/glad/include)

add_executable(PranaVox main.cpp)
target_link_libraries(PranaVox PRIVATE AK Renderer glfw)
