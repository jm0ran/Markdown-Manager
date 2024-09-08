project(Markdown-Manager)

set(Headers
    ../include/Scanner.hpp
    ../include/Element.hpp
    ../include/TextElement.hpp
    ../include/HeaderElement.hpp
    ../include/BoldElement.hpp
    ../include/ItalicElement.hpp
    ../include/HighlightedElement.hpp
)

set(CMAKE_BUILD_TYPE Debug)

set(Sources
    app.cpp 
    scanner.cpp 
    elements/TextElement.cpp 
    elements/HeaderElement.cpp
    elements/BoldElement.cpp
    elements/ItalicElement.cpp
    elements/HighlightedElement.cpp
)

include_directories(src)

add_executable(${PROJECT_NAME} ${Headers} ${Sources})
add_library(${PROJECT_NAME}-LIB ${Headers} ${Sources})

# Specify include directories for targets
target_include_directories(${PROJECT_NAME}
    PRIVATE ../include
)
target_include_directories(${PROJECT_NAME}-LIB
    PRIVATE ${CMAKE_SOURCE_DIR}/include
)