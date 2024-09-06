project (Markdown-Manager)

set(Headers
    scanner.hpp
    Element.hpp
    TextElement.hpp
)

set(CMAKE_BUILD_TYPE Debug)

set(Sources
    app.cpp
    scanner.cpp
    TextElement.cpp
)

include_directories(src)

add_executable(${PROJECT_NAME} ${Headers} ${Sources})
add_library(${PROJECT_NAME}-LIB ${Headers} ${Sources})