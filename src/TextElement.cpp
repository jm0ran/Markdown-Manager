#include "TextElement.hpp"

TextElement::TextElement(const std::string &text) { this->text = text; };

std::string TextElement::render() const {
  return "<span>" + this->text + "</span>";
};