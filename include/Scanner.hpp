#pragma once

#include <string>
#include <vector>

#include "Element.hpp"

class Scanner {
public:
  /**
   * Path to the file currently being read
   */
  std::string filePath;

  /**
   * Constructor for the scanner class
   * @param filePath the path to the file to scan
   */
  Scanner(std::string filePath);

  /**
   * Populates the children of a parent element with the line
   * @param parent the parent element to populate
   * @param line the line to populate the parent element with
   */
  void populateChildren(std::shared_ptr<Element> parent, std::string &line);

  /**
   * Process a line of text and return the element tree
   * @param line the line to process
   * @return a shared pointer to the root element of the line
   */
  std::shared_ptr<Element> processLine(std::string &line);

private:
  /**
   * Extracts a header element from the line if it exists
   * @return a shared pointer to the header element if it exists, otherwise
   * nullptr
   */
  std::shared_ptr<Element> extractHeader(std::string &line);

  /**
   * Extracts a bold element from the line if it exists
   * @return a shared pointer to the bold element if it exists, otherwise
   * nullptr
   */
  std::shared_ptr<Element> extractBold(std::string &line);

  /**
   * Extracts an italic element from the line if it exists
   * @return a shared pointer to the italic element if it exists, otherwise
   * nullptr
   */
  std::shared_ptr<Element> extractItalic(std::string &line);

  /**
   * Extracts a highlighted element from the line if it exists
   * @return a shared pointer to the highlighted element if it exists, otherwise
   * nullptr
   */
  std::shared_ptr<Element> extractHighlighted(std::string &line);

  /**
   * Extracts a strikethrough element from the line if it exists
   * @return a shared pointer to the strikethrough element if it exists,
   * otherwise nullptr
   */
  std::shared_ptr<Element> extractStrikethrough(std::string &line);

  /**
   * Extracts a text element from the line if it exists
   * @return a shared pointer to the text element if it exists, otherwise
   * nullptr
   */
  std::shared_ptr<Element> extractText(std::string &line);
};
