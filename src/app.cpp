#include <iostream>

#include "HeaderElement.hpp"
#include "Scanner.hpp"
#include "TextElement.hpp"

void log(std::string string) { std::cout << string << std::endl; }

int main(int argc, char const *argv[]) {
  Scanner scanner("./src/example.md");
  std::shared_ptr<Element> element = nullptr;
  std::string elementName = "### This is a header";
  element = scanner.readNextElement(elementName);

  if (element) {
    log("Element: " + element->render());
  }
}