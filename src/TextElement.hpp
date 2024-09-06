#pragma once

#include "Element.hpp"

class TextElement : public Element {
public:
    TextElement(const std::string& text);

    std::string render() const override;

private:
    std::string m_text;
};
