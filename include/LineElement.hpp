#pragma once

#include "Element.hpp"
#include <vector>

/**
 * Highest level element of organization in the parser as information is parsed
 * line by line, the root node of an element tree
 */
class LineElement : public Element {
public:
  LineElement();
  std::string render() const override;
  void addChild(std::shared_ptr<Element> child) override;

private:
  std::vector<std::shared_ptr<Element>> children;
};