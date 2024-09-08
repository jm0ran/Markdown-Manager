#include "HighlightedElement.hpp"

HighlightedElement::HighlightedElement() {}

std::string HighlightedElement::render() const {
  std::string renderedChildren;
  for (const std::shared_ptr<Element> &child : children) {
    renderedChildren += child->render();
  }
  return "<mark>" + renderedChildren + "</mark>";
}

void HighlightedElement::addChild(std::shared_ptr<Element> child) {
  children.push_back(child);
}