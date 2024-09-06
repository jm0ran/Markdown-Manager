#include "TextElement.hpp"

TextElement::TextElement(const std::string& text){
    m_text = text;
};
    
std::string TextElement::render() const {
    return m_text;
};