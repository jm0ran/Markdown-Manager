#pragma once

#include <vector>

#include "Element.hpp"

/**
 * Bold element class extends the Element class and represents a bold element
 * in the markdown parser
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

  /**
   * Get the children of the bold element
   * @return const std::vector<std::shared_ptr<Element>>& reference to the
   * vector of children
   */
  const std::vector<std::shared_ptr<Element>> &getChildren() const override;

private:
  /**
   * The children of the bold element stores as a vector of shared pointers to
   * elements
   */
  std::vector<std::shared_ptr<Element>> children;
};
;