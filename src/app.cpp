#include "HeaderElement.hpp"
#include "TextElement.hpp"
#include "Scanner.hpp"
#include <iostream>

void log(std::string string) { std::cout << string << std::endl; }

int main(int argc, char const *argv[]) {
  Scanner scanner("./src/example.md");
  scanner.scan();
}