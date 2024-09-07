#include "Scanner.hpp"
#include <fstream>
#include <iostream>
#include <regex>

Scanner::Scanner(std::string filePath) {
  this->path = filePath;
  std::cout << "Scanner Created " << filePath << std::endl;
}

void Scanner::scan() {
  std::cout << "Scanning " << this->path << std::endl;
  std::ifstream file;
  file.open(path);

  if (!file) {
    throw std::runtime_error("Could not open file: " + this->path);
  }

  std::string currentLine;
  while (std::getline(file, currentLine)) {
    std::cout << currentLine << std::endl;
    extractHeaders(currentLine);
  }
}

int Scanner::extractHeaders(std::string &line) {
  // Regex to match headers from range 1-6
  std::regex headerRegex("^#{1,6} .*");
  if (std::regex_match(line, headerRegex)) {
    std::cout << "Header Found: " << line << std::endl;
    return 1;
  }
  return 0;
}

std::string Scanner::nextLine() { return "Linking Worked"; }