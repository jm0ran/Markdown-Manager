#pragma once

#include "RenderInterface.hpp"

/**
 * The HTMLRenderer class implements the RenderInterface to render elements and
 * output them in an HTML compliant format
 */
class HTMLRenderer : public RenderInterface {
  /**
   * Render bold element to HTML
   */
  std::string renderBoldElement(BoldElement &element) override;

  /**
   * Render italic element to HTML
   */
  std::string renderItalicElement(ItalicElement &element) override;

  /**
   * Render highlighted element to HTML
   */
  std::string renderHighlightedElement(HighlightedElement &element) override;

  /**
   * Render strike-through element to HTML
   */
  std::string
  renderStrikethroughElement(StrikethroughElement &element) override;

  /**
   * Render text element to HTML
   */
  std::string renderTextElement(TextElement &element) override;
};