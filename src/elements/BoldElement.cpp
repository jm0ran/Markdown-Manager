#include "BoldElement.hpp"

BoldElement::BoldElement() {}

std::string BoldElement::render(RenderInterface &renderer) const {
  std::string renderedChildren;
  for (const std::shared_ptr<Element> &child : children) {
    renderedChildren += child->render(renderer);
  }
  return "<b>" + renderedChildren + "</b>";
}

void BoldElement::addChild(std::shared_ptr<Element> child) {
  children.push_back(child);
}