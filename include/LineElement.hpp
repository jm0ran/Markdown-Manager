#pragma once

#include <vector>

#include "Element.hpp"

/**
 * Highest level element of organization in the parser as information is parsed
 * line by line, the root node of an element tree
 */
class LineElement : public Element {
public:
  LineElement();
  std::string render(RenderInterface &renderer) const override;
  void addChild(std::shared_ptr<Element> child) override;

private:
  std::vector<std::shared_ptr<Element>> children;
};