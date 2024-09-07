#include "HeaderElement.hpp"
#include "TextElement.hpp"
#include "scanner.hpp"
#include <iostream>

void log(std::string string) { std::cout << string << std::endl; }

int main(int argc, char const *argv[]) {
  TextElement textElement("TextElement Content");
  HeaderElement headerElement(1);
  headerElement.addChild(std::make_shared<TextElement>(textElement));

  std::cout << "Output: " << headerElement.render() << std::endl;
  // Scanner scanner("./src/example.md");
  // scanner.scan();
}