#include "CppUTest/CommandLineTestRunner.h"

#include "TextElement.hpp"
#include "HeaderElement.hpp"

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