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
  bool extractBold();
  bool extractItalic();
  bool extractStrikethrough();
  std::shared_ptr<Element> extractText(std::string &line);
};
