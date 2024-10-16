#pragma once

#include "Element.hpp"
#include <vector>

/**
 * Bold element class extends the Element class and represents a bold element in
 * the markdown parser
 */
class BoldElement : public Element {
public:
  /**
   * Constructor for a bold element
   */
  BoldElement();

  /**
   * Render the bold element to a string value
   * @return std::string representation of the bold element
   * @param renderer the renderer object used to render this element and all
   * children
   */
  std::string render(RenderInterface &renderer) const override;

  /**
   * Add a child element to the bold element
   * @param child the child element to add
   */
  void addChild(std::shared_ptr<Element> child) override;

private:
  /**
   * The children of the bold element stores as a vector of shared pointers to
   * elements
   */
  std::vector<std::shared_ptr<Element>> children;
};
;