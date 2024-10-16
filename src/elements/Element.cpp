#include "Element.hpp"
#include <stdexcept>

const std::vector<std::shared_ptr<Element>> &Element::getChildren() const {
  throw std::runtime_error(
      "This operation is not supported or not yet implemented");
}