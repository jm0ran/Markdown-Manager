#include "CppUTest/CommandLineTestRunner.h"

#include "TextElement.hpp"
#include "HeaderElement.hpp"
#include "BoldElement.hpp"
#include "ItalicElement.hpp"
#include "HighlightedElement.hpp"
#include "StrikethroughElement.hpp"

/**
 * @brief Test Group specific to the textElement class
 */
TEST_GROUP(TEXT_ELEMENT){
   
};

/** 
 * @brief Test Group specific to the headerElement class
*/
TEST_GROUP(HEADER_ELEMENT){
   
};

/**
 * @brief Test Group specific to the boldElement class
 */
TEST_GROUP(BOLD_ELEMENT){

};

/**
 * @brief Test Group specific to the italicElement class
 */
TEST_GROUP(ITALIC_ELEMENT){
   
};

/**
 * @brief Test Group specific to the highlightedElement class
 */
TEST_GROUP(HIGHLIGHTED_ELEMENT){

};

/**
 * @brief Test Group specific to the strikethroughElement class
 */
TEST_GROUP(STRIKETHROUGH_ELEMENT){
   
};

/**
 * @brief Veirfy that a simple block of text returns in a span tag for text element construction
 */
TEST(TEXT_ELEMENT, TEXT_ELEMENT_000){
   TextElement textElement("TextElement Content");
   STRCMP_EQUAL("<span>TextElement Content</span>", textElement.render().c_str());
};

/**
 * @brief Verify that a header element with no children is created and renders with the correct level (level 1)
 */
TEST(HEADER_ELEMENT, HEADER_ELEMENT_000){
   HeaderElement headerElement(1);
   STRCMP_EQUAL("<h1></h1>", headerElement.render().c_str());
};

/**
 * @brief Verify that a header element with no children is created and renders with the correct level (level 3)
 */
TEST(HEADER_ELEMENT, HEADER_ELEMENT_001){
   HeaderElement headerElement(3);
   STRCMP_EQUAL("<h3></h3>", headerElement.render().c_str());
};

/**
 * @brief Verify that a header element created with an invalid header level (less than 1) throws an exception
 */
TEST(HEADER_ELEMENT, HEADER_ELEMENT_002){
   CHECK_THROWS(std::invalid_argument, HeaderElement(0));
};

/**
 * @brief Verify that a header element created with an invalid header level (greater than 6) throws an exception
 */
TEST(HEADER_ELEMENT, HEADER_ELEMENT_003){
   CHECK_THROWS(std::invalid_argument, HeaderElement(7));
};

/**
 * @brief Veirfy that a bold element renders as expected with no children
 */
TEST(BOLD_ELEMENT, BOLD_ELEMENT_000){
   BoldElement boldElement;
   STRCMP_EQUAL("<b></b>", boldElement.render().c_str());
};

/**
 * @brief Verify that a bold element with a child text element renders as expected
 */
TEST(BOLD_ELEMENT, BOLD_ELEMENT_001){
   BoldElement boldElement;
   boldElement.addChild(std::make_shared<TextElement>("BoldElement Content"));
   STRCMP_EQUAL("<b><span>BoldElement Content</span></b>", boldElement.render().c_str());
};

/**
 * @brief Verify that an italic element renders as expected with no children
 */
TEST(ITALIC_ELEMENT, ITALIC_ELEMENT_000){
   ItalicElement italicElement;
   STRCMP_EQUAL("<i></i>", italicElement.render().c_str());
};

/**
 * @brief Verify that an italic element with a child text element renders as expected
 */
TEST(ITALIC_ELEMENT, ITALIC_ELEMENT_001){
   ItalicElement italicElement;
   italicElement.addChild(std::make_shared<TextElement>("ItalicElement Content"));
   STRCMP_EQUAL("<i><span>ItalicElement Content</span></i>", italicElement.render().c_str());
};

/**
 * @brief Verify that a highlighted element renders as expected with no children
 */
TEST(HIGHLIGHTED_ELEMENT, HIGHLIGHTED_ELEMENT_000){
   HighlightedElement highlightedElement;
   STRCMP_EQUAL("<mark></mark>", highlightedElement.render().c_str());
};

/**
 * @brief Verify that a highlighted element with a child text element renders as expected
 */
TEST(HIGHLIGHTED_ELEMENT, HIGHLIGHTED_ELEMENT_001){
   HighlightedElement highlightedElement;
   highlightedElement.addChild(std::make_shared<TextElement>("HighlightedElement Content"));
   STRCMP_EQUAL("<mark><span>HighlightedElement Content</span></mark>", highlightedElement.render().c_str());
};

/**
 * @brief Verify that a strike through element renders as expected with no children
 */
TEST(STRIKETHROUGH_ELEMENT, STRIKETHROUGH_ELEMENT_000){
   StrikethroughElement strikethroughElement;
   STRCMP_EQUAL("<s></s>", strikethroughElement.render().c_str());
};

/**
 * @brief Verify that a strike through element with a child text element renders as expected
 */
TEST(STRIKETHROUGH_ELEMENT, STRIKETHROUGH_ELEMENT_001){
   StrikethroughElement strikethroughElement;
   strikethroughElement.addChild(std::make_shared<TextElement>("StrikethroughElement Content"));
   STRCMP_EQUAL("<s><span>StrikethroughElement Content</span></s>", strikethroughElement.render().c_str());
};

