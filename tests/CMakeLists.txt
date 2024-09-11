project (Markdown-Manager)

# include CppUTest headers
include_directories($ENV{CPPUTEST_HOME}/include)

# include CppUTest library
add_library(lib_cpputest STATIC IMPORTED)
set_property(TARGET lib_cpputest PROPERTY
            IMPORTED_LOCATION $ENV{CPPUTEST_HOME}/lib/libCppUTest.a)

set(Sources
    RunAllTests.cpp
    ElementTests.cpp
    ScannerTests.cpp
)

# Create Test Executable and link it
add_executable(TestRun ${Sources})
target_link_libraries(TestRun lib_cpputest Markdown-Manager-LIB)

target_include_directories(TestRun
    PRIVATE ../include
)