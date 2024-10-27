#include "HTMLRenderer.hpp"

// Include the header files for the elements you will be rendering, must be
// done here in addition to the forward declarations in the header file
#include "BoldElement.hpp"
#include "HighlightedElement.hpp"
#include "ItalicElement.hpp"
#include "StrikethroughElement.hpp"
#include "TextElement.hpp"

std::string HTMLRenderer::renderChildrenGeneric(
    const std::vector<std::shared_ptr<Element>> &children) {
  std::string renderedChildren;
  for (const std::shared_ptr<Element> &child : children) {
    renderedChildren += child->render(*this);
  }
  return renderedChildren;
}

std::string HTMLRenderer::renderBoldElement(const BoldElement &element) {
  const std::vector<std::shared_ptr<Element>> &children = element.getChildren();
  std::string renderedChildren = renderChildrenGeneric(children);
  return "<b>" + renderedChildren + "</b>";
}

std::string HTMLRenderer::renderItalicElement(const ItalicElement &element) {
  const std::vector<std::shared_ptr<Element>> &children = element.getChildren();
  std::string renderedChildren = renderChildrenGeneric(children);
  return "<i>" + renderedChildren + "</i>";
}

std::string
HTMLRenderer::renderHighlightedElement(const HighlightedElement &element) {
  const std::vector<std::shared_ptr<Element>> &children = element.getChildren();
  std::string renderedChildren = renderChildrenGeneric(children);
  return "<mark>" + renderedChildren + "</mark>";
}

std::string
HTMLRenderer::renderStrikethroughElement(const StrikethroughElement &element) {
  const std::vector<std::shared_ptr<Element>> &children = element.getChildren();
  std::string renderedChildren = renderChildrenGeneric(children);
  return "<s>" + renderedChildren + "</s>";
}

std::string HTMLRenderer::renderTextElement(const TextElement &element) {
  return "<span>" + element.getText() + "</span>";
}
