project (Markdown-Manager)

set(Headers
    scanner.hpp;
)

set(CMAKE_BUILD_TYPE Debug)

set(Sources
    app.cpp
    scanner.cpp;
)

include_directories(src)

add_executable(${PROJECT_NAME} ${Headers} ${Sources})
add_library(${PROJECT_NAME}-LIB ${Headers} ${Sources})