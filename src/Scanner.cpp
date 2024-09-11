#include "Scanner.hpp"
#include "HeaderElement.hpp"
#include "TextElement.hpp"

#include <fstream>
#include <iostream>
#include <regex>

Scanner::Scanner(std::string filePath) {
  this->filePath = filePath;
  std::cout << "Scanner Created " << filePath << std::endl;
}

void Scanner::scan() {
  std::cout << "Scanning " << this->filePath << std::endl;
  std::ifstream file;
  file.open(this->filePath);

  if (!file) {
    throw std::runtime_error("Could not open file: " + this->filePath);
  }

  std::string currentLine;
  while (std::getline(file, currentLine)) {
      readNextElement(currentLine);
  }
}

std::shared_ptr<Element> Scanner::readNextElement(std::string& line) {
  std::shared_ptr<Element> element = nullptr;
  if((element = extractHeader(line))){
    return element;
  }else{
    return extractText(line);
  }
}

std::shared_ptr<Element> Scanner::extractHeader(std::string& line) {
  std::regex headerRegex("^#{1,6}\\ ");
  std::smatch match;
  if (std::regex_search(line, match, headerRegex)) {
    int headerLevel = match[0].length() - 1;
    std::string content = line.substr(match[0].length());
    HeaderElement header(headerLevel);
    header.addChild(readNextElement(content));
    return std::make_shared<HeaderElement>(header);
  }
  return nullptr;
}

std::shared_ptr<Element> Scanner::extractText(std::string& line) {
  return std::make_shared<TextElement>(TextElement(line));
}