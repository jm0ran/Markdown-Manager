cmake_minimum_required(VERSION 3.10)

project(Markdown-Manager C CXX)

set (CMAKE_CXX_STANDARD 11)

set(CMAKE_C_STANDARD 90)

Set(Headers
    src/app2.h
)

Set(Sources
    src/app.cpp
    src/app2.c
)

add_executable(${PROJECT_NAME} ${Headers} ${Sources})