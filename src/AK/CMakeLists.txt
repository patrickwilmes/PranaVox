set(SOURCE_FILES
        FileIO.cpp
        FileIO.h
)

add_library(AK ${SOURCE_FILES})
target_include_directories(AK PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})