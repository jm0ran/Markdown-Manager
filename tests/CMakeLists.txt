project (Markdown-Manager)

# include CppUTest headers
include_directories($ENV{CPPUTEST_HOME}/include)

# include CppUTest library
add_library(lib_cpputest STATIC IMPORTED)
set_property(TARGET lib_cpputest PROPERTY
            IMPORTED_LOCATION $ENV{CPPUTEST_HOME}/lib/libCppUTest.a)

# Create Test Executable and link it
add_executable(TestRun sample.cpp)
target_link_libraries(TestRun lib_cpputest Markdown-Manager-LIB)