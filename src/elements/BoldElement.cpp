#include "BoldElement.hpp"

BoldElement::BoldElement() {}

std::string BoldElement::render() const {
  std::string renderedChildren;
  for (const std::shared_ptr<Element> &child : children) {
    renderedChildren += child->render();
  }
  return "<b>" + renderedChildren + "</b>";
}

void BoldElement::addChild(std::shared_ptr<Element> child) {
  children.push_back(child);
}