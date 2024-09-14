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

  void populateChildren(std::shared_ptr<Element> parent, std::string &line);

  std::shared_ptr<Element> processLine(std::string &line);

private:
  // Methods
  std::shared_ptr<Element> extractHeader(std::string &line);
  std::shared_ptr<Element> extractBold(std::string &line);
  std::shared_ptr<Element> extractItalic(std::string &line);
  std::shared_ptr<Element> extractStrikethrough(std::string &line);
  std::shared_ptr<Element> extractText(std::string &line);
};
