#include "HeaderElement.hpp"

HeaderElement::HeaderElement(int level) { this->level = level; }

std::string HeaderElement::render() const {
  std::string renderedChildren;
  for (const std::shared_ptr<Element> &child : children) {
    renderedChildren += child->render();
  }
  return "<h" + std::to_string(level) + ">" + renderedChildren + "</h" +
         std::to_string(level) + ">";
}

int HeaderElement::getLevel() const { return level; }

void HeaderElement::addChild(std::shared_ptr<Element> child) {
  children.push_back(child);
}