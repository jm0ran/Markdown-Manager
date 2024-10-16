#include "StrikethroughElement.hpp"

StrikethroughElement::StrikethroughElement() {}

std::string StrikethroughElement::render(RenderInterface &renderer) const {
  std::string renderedChildren;
  for (const std::shared_ptr<Element> &child : children) {
    renderedChildren += child->render(renderer);
  }
  return "<s>" + renderedChildren + "</s>";
}

void StrikethroughElement::addChild(std::shared_ptr<Element> child) {
  children.push_back(child);
}