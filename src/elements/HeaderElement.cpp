#include "HeaderElement.hpp"

HeaderElement::HeaderElement(int level) {
  // Check if the level is between 1 and 6
  if (level < 1 || level > 6) {
    throw std::invalid_argument(
        "Header level must be between 1 and 6 inclusive");
  }

  this->level = level;
}

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