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
 * @brief Verify that the processLine can read a simple header element
 */
TEST(READ_NEXT_ELEMENT, READ_NEXT_ELEMENT_000){
    std::string testLine = "# Header 1 Content";
    std::shared_ptr<Element> element = scanner->processLine(testLine);
    STRCMP_EQUAL("<h1><span>Header 1 Content</span></h1>", element->render().c_str());
};

/**
 * @brief Verify that the processLine can read a simple text element
 */
TEST(READ_NEXT_ELEMENT, READ_NEXT_ELEMENT_001){
    std::string testLine = "Text Element Content";
    std::shared_ptr<Element> element = scanner->processLine(testLine);
    STRCMP_EQUAL("<span>Text Element Content</span>", element->render().c_str());
};

/**
 * @brief Verify that an invalid header (too many #) is read as a text element
 */
TEST(READ_NEXT_ELEMENT, READ_NEXT_ELEMENT_002){
    std::string testLine = "####### Invalid Header Content";
    std::shared_ptr<Element> element = scanner->processLine(testLine);
    STRCMP_EQUAL("<span>####### Invalid Header Content</span>", element->render().c_str());
}

/**
 * @brief Verify that an invalid header (no space) is read as a text element
 */
TEST(READ_NEXT_ELEMENT, READ_NEXT_ELEMENT_003){
    std::string testLine = "######Invalid Header Content";
    std::shared_ptr<Element> element = scanner->processLine(testLine);
    STRCMP_EQUAL("<span>######Invalid Header Content</span>", element->render().c_str());
}

/**
 * @brief Verify that an invalid header (not at start of line) is read as a text element
 */
TEST(READ_NEXT_ELEMENT, READ_NEXT_ELEMENT_004){
    std::string testLine = "BAD ###### Invalid Header Content";
    std::shared_ptr<Element> element = scanner->processLine(testLine);
    STRCMP_EQUAL("<span>BAD ###### Invalid Header Content</span>", element->render().c_str());
}

/**
 * @brief Verify that a line with just bold text returns a bold element
 */
TEST(READ_NEXT_ELEMENT, READ_NEXT_ELEMENT_005){
    std::string testLine = "**Bold Element**";
    std::shared_ptr<Element> element = scanner->processLine(testLine);
    STRCMP_EQUAL("<b><span>Bold Element</span></b>", element->render().c_str());
}

/**
 * @brief Verify that a line with regular text follows by bold text renders as expected
 */
// TEST(READ_NEXT_ELEMENT, READ_NEXT_ELEMENT_006){
//     std::string testLine = "Regular Text **Bold Element**";
//     std::shared_ptr<Element> element = scanner->readNextElement(testLine);
//     STRCMP_EQUAL("<span>Regular Text </span><b><span>Bold Element</span></b>", element->render().c_str());
// }