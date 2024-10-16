#include "ItalicElement.hpp"

ItalicElement::ItalicElement() {}

std::string ItalicElement::render(RenderInterface &renderer) const {
  std::string renderedChildren;
  for (const std::shared_ptr<Element> &child : children) {
    renderedChildren += child->render(renderer);
  }
  return "<i>" + renderedChildren + "</i>";
}

void ItalicElement::addChild(std::shared_ptr<Element> child) {
  children.push_back(child);
}
