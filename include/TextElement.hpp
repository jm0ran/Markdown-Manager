#pragma once

#include "Element.hpp"

class TextElement : public Element {
public:
  /**
   * Constructor for a text element
   * @param text text content of the element
   */
  TextElement(const std::string text);

  /**
   * Render the text element to a string value
   * @param renderer the renderer object used to render this element and all
   * children
   * @return std::string representation of the text element
   */
  std::string render(RenderInterface &renderer) const override;

  /**
   * Add a child element to the text element
   * @param child the child element to add
   */
  void addChild(std::shared_ptr<Element> child) override;

  /**
   * Get the text content of the text element
   * @return std::string text content of the element
   */
  std::string getText() const;

private:
  /**
   * The text content of the text element
   */
  std::string text;
};
