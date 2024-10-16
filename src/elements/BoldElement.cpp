#include "BoldElement.hpp"

BoldElement::BoldElement() {}

std::string BoldElement::render(RenderInterface &renderer) const {
  return renderer.renderBoldElement(*this);
}

void BoldElement::addChild(std::shared_ptr<Element> child) {
  children.push_back(child);
}

const std::vector<std::shared_ptr<Element>> &BoldElement::getChildren() const {
  return children;
}