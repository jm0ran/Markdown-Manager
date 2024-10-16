#pragma once

#include <string>

// Forward declarations
class BoldElement;
class HighlightedElement;
class ItalicElement;
class StrikethroughElement;
class TextElement;

/**
 * The RenderInterface class is an interface for rendering elements in the
 * markdown parser, used as an adapter to allow for different methods of
 * rendering (json, html, xml, etc.)
 */
class RenderInterface {
public:
  /**
   * Default RenderInterface Constructor
   */
  virtual ~RenderInterface() = default;

  /**
   * Renders the given bold element to a string value
   * @param element the bold element to render
   */
  virtual std::string renderBoldElement(BoldElement &element) = 0;

  /**
   * Renders the given italic element to a string value
   * @param element the italic element to render
   */
  virtual std::string renderItalicElement(ItalicElement &element) = 0;

  /**
   * Renders the given highlighted element to a string value
   * @param element the highlighted element to render
   */
  virtual std::string renderHighlightedElement(HighlightedElement &element) = 0;

  /**
   * Renders the given strikethrough element to a string value
   * @param element the strikethrough element to render
   */
  virtual std::string
  renderStrikethroughElement(StrikethroughElement &element) = 0;

  /**
   * Renders the given text element to a string value
   * @param element the text element to render
   */
  virtual std::string renderTextElement(TextElement &element) = 0;
};