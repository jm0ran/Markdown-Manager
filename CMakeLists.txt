cmake_minimum_required(VERSION 3.10)

project(Markdown-Manager C CXX)

set (CMAKE_CXX_STANDARD 11)

set(CMAKE_C_STANDARD 90)

set(Headers
    src/scanner.hpp;
)

set(CMAKE_BUILD_TYPE Debug)

set(Sources
    src/app.cpp
    src/scanner.cpp;
)

include_directories(src)

add_executable(${PROJECT_NAME} ${Headers} ${Sources})

# Add compiler flags for all configurations
if(CMAKE_COMPILER_IS_GNUCXX)
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall)
endif()