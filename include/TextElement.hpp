#pragma once

#include "Element.hpp"

class TextElement : public Element {
public:
  TextElement(const std::string text);

  std::string render(RenderInterface &renderer) const override;

  void addChild(std::shared_ptr<Element> child) override;

private:
  std::string text;
};
