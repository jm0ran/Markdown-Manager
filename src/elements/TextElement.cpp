#include "TextElement.hpp"
#include <iostream>

TextElement::TextElement(const std::string text) { this->text = text; };

std::string TextElement::render(RenderInterface &renderer) const {
  return "<span>" + this->text + "</span>";
};

void TextElement::addChild(std::shared_ptr<Element> child) {
  throw std::runtime_error("Cannot add child to TextElement");
}