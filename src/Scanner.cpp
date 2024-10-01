#include "Scanner.hpp"
#include "BoldElement.hpp"
#include "HeaderElement.hpp"
#include "HighlightedElement.hpp"
#include "ItalicElement.hpp"
#include "LineElement.hpp"
#include "StrikethroughElement.hpp"
#include "TextElement.hpp"

#include <regex>

Scanner::Scanner(std::string filePath) { this->filePath = filePath; }

std::shared_ptr<Element> Scanner::processLine(std::string &line) {
  std::shared_ptr<LineElement> linePointer =
      std::make_shared<LineElement>(LineElement());
  this->populateChildren(linePointer, line);
  return linePointer;
}

/**
 * Populates the children of a parent element with the line
 * @param parent the parent element to populate
 * @param line the line to populate the parent element with
 */
void Scanner::populateChildren(std::shared_ptr<Element> parent,
                               std::string &line) {
  while (line.length() > 0) {
    std::shared_ptr<Element> element = nullptr;
    if ((element = extractHeader(line))) {
      parent->addChild(element);
    } else if ((element = extractBold(line))) {
      parent->addChild(element);
    } else if ((element = extractItalic(line))) {
      parent->addChild(element);
    } else if ((element = extractHighlighted(line))) {
      parent->addChild(element);
    } else if ((element = extractStrikethrough(line))) {
      parent->addChild(element);
    } else {
      parent->addChild(extractText(line));
    }
  }
}

/**
 * Extracts a header element from the line if it exists
 * @return a shared pointer to the header element if it exists, otherwise
 * nullptr
 */
std::shared_ptr<Element> Scanner::extractHeader(std::string &line) {
  std::regex headerRegex("^#{1,6}\\ ");
  std::smatch match;
  if (std::regex_search(line, match, headerRegex)) {
    int headerLevel = match[0].length() - 1;
    std::shared_ptr<HeaderElement> header =
        std::make_shared<HeaderElement>(HeaderElement(headerLevel));
    std::string remaining = line.substr(match[0].length());
    this->populateChildren(header, remaining);
    line.erase(0, line.length());
    return header;
  } else {
    return nullptr;
  }
}

/**
 * Extracts a text element from the line if it exists
 * @return a shared pointer to the text element if it exists, otherwise nullptr
 */
std::shared_ptr<Element> Scanner::extractText(std::string &line) {
  if (line.empty()) {
    return nullptr;
  }

  std::regex textRegex("(.*?)(\\*\\*.*\\*\\*|\\*.*\\*|==.*==|~~.*~~)");
  std::smatch match;
  if (std::regex_search(line, match, textRegex)) {
    std::shared_ptr<TextElement> textElement =
        std::make_shared<TextElement>(TextElement(match[1]));
    line.erase(0, match[1].length());
    return textElement;
  } else {
    std::shared_ptr<TextElement> textElement =
        std::make_shared<TextElement>(TextElement(line));
    line.erase(0, line.length());
    return textElement;
  }
}

/**
 * Extracts a bold element from the line if it exists
 * @return a shared pointer to the bold element if it exists, otherwise nullptr
 */
std::shared_ptr<Element> Scanner::extractBold(std::string &line) {
  std::regex boldRegex("^\\*\\*.*\\*\\*");
  std::smatch match;
  if (std::regex_search(line, match, boldRegex)) {
    std::shared_ptr<BoldElement> boldElement =
        std::make_shared<BoldElement>(BoldElement());
    std::string content = line.substr(2, match[0].length() - 4);
    populateChildren(boldElement, content);
    line.erase(0, match[0].length());
    return boldElement;
  }
  return nullptr;
}

/**
 * Extracts an italic element from the line if it exists
 * @return a shared pointer to the italic element if it exists, otherwise
 * nullptr
 */
std::shared_ptr<Element> Scanner::extractItalic(std::string &line) {
  std::regex italicRegex("^\\*.*\\*");
  std::smatch match;
  if (std::regex_search(line, match, italicRegex)) {
    std::shared_ptr<ItalicElement> italicElement =
        std::make_shared<ItalicElement>(ItalicElement());
    std::string content = line.substr(1, match[0].length() - 2);
    populateChildren(italicElement, content);
    line.erase(0, match[0].length());
    return italicElement;
  }
  return nullptr;
}

/**
 * Extracts a highlighted element from the line if it exists
 * @return a shared pointer to the highlighted element if it exists, otherwise
 * nullptr
 */
std::shared_ptr<Element> Scanner::extractHighlighted(std::string &line) {
  std::regex highlightRegex("^==.*==");
  std::smatch match;
  if (std::regex_search(line, match, highlightRegex)) {
    std::shared_ptr<HighlightedElement> highlightedElement =
        std::make_shared<HighlightedElement>(HighlightedElement());
    std::string content = line.substr(2, match[0].length() - 4);
    populateChildren(highlightedElement, content);
    line.erase(0, match[0].length());
    return highlightedElement;
  }
  return nullptr;
}

/**
 * Extracts a strikethrough element from the line if it exists
 * @return a shared pointer to the strikethrough element if it exists, otherwise
 * nullptr
 */
std::shared_ptr<Element> Scanner::extractStrikethrough(std::string &line) {
  std::regex strikethroughRegex("^~~.*~~");
  std::smatch match;
  if (std::regex_search(line, match, strikethroughRegex)) {
    std::shared_ptr<StrikethroughElement> strikethroughElement =
        std::make_shared<StrikethroughElement>(StrikethroughElement());
    std::string content = line.substr(2, match[0].length() - 4);
    populateChildren(strikethroughElement, content);
    line.erase(0, match[0].length());
    return strikethroughElement;
  }
  return nullptr;
}