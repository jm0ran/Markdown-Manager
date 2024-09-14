#include "LineElement.hpp"
#include <iostream>

LineElement::LineElement() {}

std::string LineElement::render() const {
  std::string renderedChildren;
  for (const std::shared_ptr<Element> &child : this->children) {
    renderedChildren += child->render();
  }
  return renderedChildren;
}

void LineElement::addChild(std::shared_ptr<Element> child) {
  children.push_back(child);
}
