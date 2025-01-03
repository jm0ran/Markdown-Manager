#pragma once

#include <string>

// Forward declarations
class BoldElement;
class HighlightedElement;
class ItalicElement;
class StrikethroughElement;
class TextElement;
class Element;

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
   * @param element the bold element to render, const
   */
  virtual std::string renderBoldElement(const BoldElement &element) = 0;

  /**
   * Renders the given italic element to a string value
   * @param element the italic element to render
   */
  virtual std::string renderItalicElement(const ItalicElement &element) = 0;

  /**
   * Renders the given highlighted element to a string value
   * @param element the highlighted element to render
   */
  virtual std::string
  renderHighlightedElement(const HighlightedElement &element) = 0;

  /**
   * Renders the given strikethrough element to a string value
   * @param element the strikethrough element to render
   */
  virtual std::string
  renderStrikethroughElement(const StrikethroughElement &element) = 0;

  /**
   * Renders the given text element to a string value
   * @param element the text element to render
   */
  virtual std::string renderTextElement(const TextElement &element) = 0;
};