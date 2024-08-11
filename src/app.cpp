#include <iostream>
#include "scanner.hpp"

void log(std::string string){
    std::cout << string << std::endl;
}

int main(int argc, char const *argv[])
{
    Scanner scanner("./src/example.md");
    scanner.scan();
}