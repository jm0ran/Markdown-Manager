#include "ItalicElement.hpp"

ItalicElement::ItalicElement() {}

std::string ItalicElement::render(RenderInterface &renderer) const {
  return renderer.renderItalicElement(*this);
}

void ItalicElement::addChild(std::shared_ptr<Element> child) {
  children.push_back(child);
}

const std::vector<std::shared_ptr<Element>> &
ItalicElement::getChildren() const {
  return children;
}