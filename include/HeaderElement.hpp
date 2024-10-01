#pragma once

#include "Element.hpp"
#include <vector>
#include <stdexcept>

/**
 * Header element class extends the Element class and represents a header
 * element in the markdown parser
 */
class HeaderElement : public Element {
public:
  /**
   * Constructor for a header element
   * @param level the level of the header element, should be between 1-6
   * inclusive
   */
  HeaderElement(int level);

  /**
   * Render the header element to a string value
   * @return std::string representation of the header element
   */
  std::string render() const override;

  /**
   * Get the level of the header element
   * @return int level of the header element
   */
  int getLevel() const;

  /**
   * Add a child element to the header element
   * @param child the child element to add
   */
  void addChild(std::shared_ptr<Element> child) override;

private:
  /**
   * The level of the header element
   */
  int level;

  /**
   * The children of the header element stores as a vector of shared pointers to
   * elements
   */
  std::vector<std::shared_ptr<Element>> children;
};