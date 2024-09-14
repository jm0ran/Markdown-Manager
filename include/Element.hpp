#pragma once

#include <string>

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
   * @return std::string representation of the element
   */
  virtual std::string render() const = 0;

  /**
   * Add a child element to the current element, implemented by children of this
   * class
   * @param
   * @return
   */
  virtual void addChild(std::shared_ptr<Element> child) = 0;
};