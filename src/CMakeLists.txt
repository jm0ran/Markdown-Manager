project(Markdown-Manager)

set(Headers
    ../include/Scanner.hpp
    ../include/Element.hpp
    ../include/TextElement.hpp
    ../include/HeaderElement.hpp
    ../include/BoldElement.hpp
    ../include/ItalicElement.hpp
    ../include/HighlightedElement.hpp
    ../include/StrikethroughElement.hpp
    ../include/LineElement.hpp
    ../include/RenderInterface.hpp
    ../include/HTMLRenderer.hpp
)

set(CMAKE_BUILD_TYPE Debug)

set(Sources
    app.cpp 
    Scanner.cpp 
    elements/TextElement.cpp 
    elements/HeaderElement.cpp
    elements/BoldElement.cpp
    elements/ItalicElement.cpp
    elements/HighlightedElement.cpp
    elements/StrikethroughElement.cpp
    elements/LineElement.cpp
    elements/Element.cpp
    renderers/HTMLRenderer.cpp
)

# Format code with clang-format
execute_process(
    WORKING_DIRECTORY src/
    COMMAND clang-format -i ${Sources} ${Headers}
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