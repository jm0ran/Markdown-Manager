#pragma once

#include <memory>
#include <string>

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
   * @return
   */
  virtual void addChild(std::shared_ptr<Element> child) = 0;
};