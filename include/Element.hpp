#pragma once

#include <memory>
#include <string>
#include <vector>

#include "RenderInterface.hpp"

/**
 * The Element class is the base class for all elements in the markdown parser,
 * it utilizes polymorphism to allow nesting of elements and a simple render
 * method to render the data at any level of the element tree
 */
class Element {
public:
  /**
   * Default Element Constructor
   */
  Element() = default;

  /**
   * Virtual destructor to ensure proper cleanup of derived classes
   */
  virtual ~Element() = default;

  /**
   * Render the given element to a string value, implemented by children of this
   * class
   * @param renderer the renderer object used to render this element and all
   * children
   * @return std::string representation of the element
   */
  virtual std::string render(RenderInterface &renderer) const = 0;

  /**
   * Add a child element to the current element, implemented by children of this
   * class
   * @param child the child element to add
   * @return void
   */
  virtual void addChild(std::shared_ptr<Element> child) = 0;

  /**
   * Gets a reference to the vector of children that this element has, to be
   * used by renderer classes
   * @return const std::vector<std::shared_ptr<Element>>& reference to the
   * vector of children
   */
  virtual const std::vector<std::shared_ptr<Element>> &getChildren() const;
};