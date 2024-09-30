#include "CppUTest/CommandLineTestRunner.h"

#include "Scanner.hpp"

/**
 * Variables to be used across tests
 */
std::shared_ptr<Scanner> scanner = nullptr;

/**
 * @brief Test Group specific to the ReadNextElement method
 */
TEST_GROUP(PROCESS_LINE){
    void setup(){
        scanner = std::make_shared<Scanner>(std::string("test.md"));
    }

    void teardown(){
        scanner = nullptr;
    }
};

/**
 * @brief Verify that the processLine can read a simple text element
 */
TEST(PROCESS_LINE, TEXT_ELEMENT_000){
    std::string testLine = "Text Element Content";
    std::shared_ptr<Element> element = scanner->processLine(testLine);
    STRCMP_EQUAL("<span>Text Element Content</span>", element->render().c_str());
};

/** 
 * @brief Verify that the processLine can read a simple header element
 */
TEST(PROCESS_LINE, HEADER_ELEMENT_000){
    std::string testLine = "# Header 1 Content";
    std::shared_ptr<Element> element = scanner->processLine(testLine);
    STRCMP_EQUAL("<h1><span>Header 1 Content</span></h1>", element->render().c_str());
};

/**
 * @brief Verify that an invalid header (too many #) is read as a text element
 */
TEST(PROCESS_LINE, HEADER_ELEMENT_001){
    std::string testLine = "####### Invalid Header Content";
    std::shared_ptr<Element> element = scanner->processLine(testLine);
    STRCMP_EQUAL("<span>####### Invalid Header Content</span>", element->render().c_str());
}

/**
 * @brief Verify that an invalid header (no space) is read as a text element
 */
TEST(PROCESS_LINE, HEADER_ELEMENT_002){
    std::string testLine = "######Invalid Header Content";
    std::shared_ptr<Element> element = scanner->processLine(testLine);
    STRCMP_EQUAL("<span>######Invalid Header Content</span>", element->render().c_str());
}

/**
 * @brief Verify that an invalid header (not at start of line) is read as a text element
 */
TEST(PROCESS_LINE, HEADER_ELEMENT_003){
    std::string testLine = "BAD ###### Invalid Header Content";
    std::shared_ptr<Element> element = scanner->processLine(testLine);
    STRCMP_EQUAL("<span>BAD ###### Invalid Header Content</span>", element->render().c_str());
}

/**
 * @brief Verify that a line with just bold text returns a bold element
 */
TEST(PROCESS_LINE, BOLD_ELEMENT_000){
    std::string testLine = "**Bold Element**";
    std::shared_ptr<Element> element = scanner->processLine(testLine);
    STRCMP_EQUAL("<b><span>Bold Element</span></b>", element->render().c_str());
}

/**
 * @brief Verify that a line with regular text follows by bold text renders as expected
 */
TEST(PROCESS_LINE, BOLD_ELEMENT_001){
    std::string testLine = "Regular Text **Bold Element**";
    std::shared_ptr<Element> element = scanner->processLine(testLine);
    STRCMP_EQUAL("<span>Regular Text </span><b><span>Bold Element</span></b>", element->render().c_str());
}

/**
 * @brief Verify that a line with bold text followed by regular text renders as expected
 */
TEST(PROCESS_LINE, BOLD_ELEMENT_002){
    std::string testLine = "**Bold Element** Regular Text";
    std::shared_ptr<Element> element = scanner->processLine(testLine);
    STRCMP_EQUAL("<b><span>Bold Element</span></b><span> Regular Text</span>", element->render().c_str());
}

/**
 * @brief Verify that a line with just an italic element renders as expected
 */
TEST(PROCESS_LINE, ITALIC_ELEMENT_000){
    std::string testLine = "*Italic Element*";
    std::shared_ptr<Element> element = scanner->processLine(testLine);
    STRCMP_EQUAL("<i><span>Italic Element</span></i>", element->render().c_str());
}

/**
 * @brief Verify that a line with regular text followed by an italic element renders as expected
 */
TEST(PROCESS_LINE, ITALIC_ELEMENT_001){
    std::string testLine = "Regular Text *Italic Element*";
    std::shared_ptr<Element> element = scanner->processLine(testLine);
    STRCMP_EQUAL("<span>Regular Text </span><i><span>Italic Element</span></i>", element->render().c_str());
}

/**
 * @brief Verify that a line with just a highlighted element renders as expected
 */
TEST(PROCESS_LINE, HIGHLIGHTED_ELEMENT_000){
    std::string testLine = "==Highlighted Element==";
    std::shared_ptr<Element> element = scanner->processLine(testLine);
    STRCMP_EQUAL("<mark><span>Highlighted Element</span></mark>", element->render().c_str());
}

/**
 * @brief Verify that a line with regular text followed by a highlighted element renders as expected
 */
TEST(PROCESS_LINE, HIGHLIGHTED_ELEMENT_001){
    std::string testLine = "Regular Text ==Highlighted Element==";
    std::shared_ptr<Element> element = scanner->processLine(testLine);
    STRCMP_EQUAL("<span>Regular Text </span><mark><span>Highlighted Element</span></mark>", element->render().c_str());
}
