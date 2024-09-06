#include <iostream>
#include "scanner.hpp"
#include "TextElement.hpp"

void log(std::string string){
    std::cout << string << std::endl;
}

int main(int argc, char const *argv[])
{
    TextElement TextElement("TextElement Content");
    std::cout << "Output: " << TextElement.render() << std::endl;
    // Scanner scanner("./src/example.md");
    // scanner.scan();
}