#include "CppUTest/CommandLineTestRunner.h"

#include "Scanner.hpp"

/**
 * Variables to be used across tests
 */
std::shared_ptr<Scanner> scanner = nullptr;

/**
 * @brief Test Group specific to the ReadNextElement method
 */
TEST_GROUP(READ_NEXT_ELEMENT){
    void setup(){
        scanner = std::make_shared<Scanner>(std::string("test.md"));
    }

    void teardown(){
        scanner = nullptr;
    }
};

/** 
 * @brief Verify that the readNextElement can read a simple header element
 */
TEST(READ_NEXT_ELEMENT, READ_NEXT_ELEMENT_000){
    std::string testLine = "# Header 1 Content";
    std::shared_ptr<Element> element = scanner->readNextElement(testLine);
    STRCMP_EQUAL("<h1><span>Header 1 Content</span></h1>", element->render().c_str());
};

/**
 * @brief Verify that the readNextElement can read a simple text element
 */
TEST(READ_NEXT_ELEMENT, READ_NEXT_ELEMENT_001){
    std::string testLine = "Text Element Content";
    std::shared_ptr<Element> element = scanner->readNextElement(testLine);
    STRCMP_EQUAL("<span>Text Element Content</span>", element->render().c_str());
};
