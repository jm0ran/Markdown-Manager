#include "Scanner.hpp"
#include "BoldElement.hpp"
#include "HeaderElement.hpp"
#include "TextElement.hpp"

#include <fstream>
#include <iostream>
#include <regex>

Scanner::Scanner(std::string filePath) { this->filePath = filePath; }

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

std::shared_ptr<Element> Scanner::readNextElement(std::string &line) {
  std::shared_ptr<Element> element = nullptr;
  if ((element = extractHeader(line))) {
    return element;
  } else if ((element = extractBold(line))) {
    return element;
  } else {
    return extractText(line);
  }
}

std::shared_ptr<Element> Scanner::extractHeader(std::string &line) {
  std::regex headerRegex("^#{1,6}\\ ");
  std::smatch match;
  if (std::regex_search(line, match, headerRegex)) {
    int headerLevel = match[0].length() - 1;
    HeaderElement header(headerLevel);
    std::string content = line.substr(match[0].length());
    std::shared_ptr<Element> nextElement = readNextElement(content);
    if (nextElement) {
      header.addChild(nextElement);
    }
    return std::make_shared<HeaderElement>(header);
  } else {
    return nullptr;
  }
}

std::shared_ptr<Element> Scanner::extractText(std::string &line) {
  if (line.empty()) {
    return nullptr;
  } else {
    // std::regex preTextRegex("^(.*?)(\\*\\*.*\\*\\*)");
    // std::smatch match;
    // if (std::regex_search(line, match, preTextRegex)) {
    //   // trim text off of line
    //   return nullptr;
    //   // return std::make_shared<TextElement>(textElement);
    // } else {
    return std::make_shared<TextElement>(TextElement(line));
    //}
  }
}

std::shared_ptr<Element> Scanner::extractBold(std::string &line) {
  std::regex boldRegex("^\\*\\*.*\\*\\*");
  std::smatch match;
  if (std::regex_search(line, match, boldRegex)) {
    BoldElement boldElement;
    std::string content = line.substr(2, line.length() - 4);
    std::shared_ptr<Element> nextElement = readNextElement(content);
    if (nextElement) {
      boldElement.addChild(nextElement);
    }
    return std::make_shared<BoldElement>(boldElement);
  }
  return nullptr;
}