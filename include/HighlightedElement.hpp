#pragma once

#include "Element.hpp"
#include <vector>

/**
 * Highlighted element class extends the Element class and represents a
 * highlighted element in the markdown parser
 */
class HighlightedElement : public Element {
public:
  /**
   * Constructor for a highlighted element
   */
  HighlightedElement();

  /**
   * Render the highlighted element to a string value
   * @param renderer the renderer object used to render this element and all
   * children
   * @return std::string representation of the highlighted element
   */
  std::string render(RenderInterface &renderer) const override;

  /**
   * Add a child element to the highlighted element
   * @param child the child element to add
   */
  void addChild(std::shared_ptr<Element> child) override;

private:
  /**
   * The children of the highlighted element stored as a vector of shared
   * pointers to elements
   */
  std::vector<std::shared_ptr<Element>> children;
};
