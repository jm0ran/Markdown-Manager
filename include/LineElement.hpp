#pragma once

#include <vector>

#include "Element.hpp"

/**
 * Highest level element of organization in the parser as information is parsed
 * line by line, the root node of an element tree
 */
class LineElement : public Element {
public:
  /**
   * Constructor for a line element
   */
  LineElement();

  /**
   * Render the line element to a string value
   * @param renderer the renderer object used to render this element and all
   * children
   * @return std::string representation of the line element
   */
  std::string render(RenderInterface &renderer) const override;

  /**
   * Add a child element to the line element
   * @param child the child element to add
   */
  void addChild(std::shared_ptr<Element> child) override;

private:
  /**
   * The children of the line element stored as a vector of shared pointers to
   * elements
   */
  std::vector<std::shared_ptr<Element>> children;
};