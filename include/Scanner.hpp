#pragma once

#include <string>
#include <vector>

class Scanner {
public:
  // Variables
  std::string filePath;

  // Methods
  Scanner(std::string filePath);
  void readNextElement(std::string& line);
  void scan();

private:
  // Methods
  bool extractHeader(std::string& line);
  bool extractBold();
  bool extractItalic();
  bool extractStrikethrough();
  bool extractText();
};
