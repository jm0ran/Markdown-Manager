#include "HTMLRenderer.hpp"

// Include the header files for the elements you will be rendering, must be done
// here in addition to the forward declarations in the header file
#include "BoldElement.hpp"
#include "HighlightedElement.hpp"
#include "ItalicElement.hpp"
#include "StrikethroughElement.hpp"
#include "TextElement.hpp"

std::string HTMLRenderer::renderBoldElement(const BoldElement &element) {
  const std::vector<std::shared_ptr<Element>> &children = element.getChildren();
  std::string renderedChildren;
  for (const std::shared_ptr<Element> &child : children) {
    renderedChildren += child->render(*this);
  }
  return "<b>" + renderedChildren + "</b>";
}

std::string HTMLRenderer::renderItalicElement(ItalicElement &element) {
  return "";
}

std::string
HTMLRenderer::renderHighlightedElement(HighlightedElement &element) {
  return "";
}

std::string
HTMLRenderer::renderStrikethroughElement(StrikethroughElement &element) {
  return "";
}

std::string HTMLRenderer::renderTextElement(TextElement &element) { return ""; }