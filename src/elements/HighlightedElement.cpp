#include "HighlightedElement.hpp"

HighlightedElement::HighlightedElement() {}

std::string HighlightedElement::render(RenderInterface &renderer) const {
  return renderer.renderHighlightedElement(*this);
}

void HighlightedElement::addChild(std::shared_ptr<Element> child) {
  children.push_back(child);
}

const std::vector<std::shared_ptr<Element>> &
HighlightedElement::getChildren() const {
  return children;
}