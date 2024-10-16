#pragma once

#include "Element.hpp"
#include <vector>

/**
 * Strikethrough element class extends the Element class and represents a
 * strikethrough element in the markdown parser
 */
class StrikethroughElement : public Element {
public:
  /**
   * Constructor for a strikethrough element
   */
  StrikethroughElement();

  /**
   * Render the strikethrough element to a string value
   * @param renderer the renderer object used to render this element and all
   * children
   * @return std::string representation of the strikethrough element
   */
  std::string render(RenderInterface &renderer) const override;

  /**
   * Add a child element to the strikethrough element
   * @param child the child element to add
   */
  void addChild(std::shared_ptr<Element> child) override;

private:
  /**
   * The children of the strikethrough element stored as a vector of shared
   * pointers to elements
   */
  std::vector<std::shared_ptr<Element>> children;
};
