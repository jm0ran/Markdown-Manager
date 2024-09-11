#pragma once

#include "Element.hpp"

#include <string>
#include <vector>

class Scanner {
public:
  // Variables
  std::string filePath;

  // Methods
  Scanner(std::string filePath);
  std::shared_ptr<Element> readNextElement(std::string &line);
  void scan();

private:
  // Methods
  std::shared_ptr<Element> extractHeader(std::string &line);
  std::shared_ptr<Element> extractBold(std::string &line);
  std::shared_ptr<Element> extractItalic(std::string &line);
  std::shared_ptr<Element> extractStrikethrough(std::string &line);
  std::shared_ptr<Element> extractText(std::string &line);
};
