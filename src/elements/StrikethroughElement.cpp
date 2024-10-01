#include "StrikethroughElement.hpp"

StrikethroughElement::StrikethroughElement() {}

std::string StrikethroughElement::render() const {
  std::string renderedChildren;
  for (const std::shared_ptr<Element> &child : children) {
    renderedChildren += child->render();
  }
  return "<s>" + renderedChildren + "</s>";
}

void StrikethroughElement::addChild(std::shared_ptr<Element> child) {
  children.push_back(child);
}