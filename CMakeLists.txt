cmake_minimum_required(VERSION 3.10)

project(Markdown-Manager)

set (CMAKE_CXX_STANDARD 17)

set(CMAKE_C_STANDARD 90)

enable_language(C)
enable_language(CXX)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)

add_subdirectory(tests)
add_subdirectory(src)

# # Add compiler flags for all configurations
# if(CMAKE_COMPILER_IS_GNUCXX)
#     target_compile_options(${PROJECT_NAME} PRIVATE -Wall)
# endif()