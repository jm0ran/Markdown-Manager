#include "HighlightedElement.hpp"

HighlightedElement::HighlightedElement() {}

std::string HighlightedElement::render(RenderInterface &renderer) const {
  std::string renderedChildren;
  for (const std::shared_ptr<Element> &child : children) {
    renderedChildren += child->render(renderer);
  }
  return "<mark>" + renderedChildren + "</mark>";
}

void HighlightedElement::addChild(std::shared_ptr<Element> child) {
  children.push_back(child);
}