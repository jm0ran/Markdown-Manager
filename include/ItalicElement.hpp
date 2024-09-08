#pragma once

#include "Element.hpp"
#include <vector>

/**
 * Italic element class extends the Element class and represents a italic element in the markdown parser
 */
class ItalicElement : public Element {
public:
  /**
   * Constructor for a italic element
   */
  ItalicElement();

  /**
   * Render the italic element to a string value
   * @return std::string representation of the italic element
   */
  std::string render() const override;

  /**
   * Add a child element to the italic element
   * @param child the child element to add
   */
  void addChild(std::shared_ptr<Element> child);

private:
  /**
   * The children of the italic element stores as a vector of shared pointers to
   * elements
   */
  std::vector<std::shared_ptr<Element>> children;
};
;