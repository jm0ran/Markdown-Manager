#pragma once

#include <memory>
#include <vector>

#include "RenderInterface.hpp"

/**
 * The HTMLRenderer class implements the RenderInterface to render elements and
 * output them in an HTML compliant format
 */
class HTMLRenderer : public RenderInterface {
public:
  /**
   * Render bold element to HTML
   */
  std::string renderBoldElement(const BoldElement &element) override;

  /**
   * Render italic element to HTML
   */
  std::string renderItalicElement(const ItalicElement &element) override;

  /**
   * Render highlighted element to HTML
   */
  std::string
  renderHighlightedElement(const HighlightedElement &element) override;

  /**
   * Render strike-through element to HTML
   */
  std::string
  renderStrikethroughElement(const StrikethroughElement &element) override;

  /**
   * Render text element to HTML
   */
  std::string renderTextElement(const TextElement &element) override;

private:
  std::string
  renderChildrenGeneric(const std::vector<std::shared_ptr<Element>> &children);
};