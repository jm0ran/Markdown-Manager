#include "CppUTest/CommandLineTestRunner.h"
#include "../src/scanner.hpp"

TEST_GROUP(FirstTestGroup)
{
};

TEST(FirstTestGroup, FirstTest)
{
   Scanner scanner = Scanner("TestString");
   std::string nextLine = scanner.nextLine();
   FAIL(nextLine.c_str());
};

int main(int ac, char** av)
{
   return CommandLineTestRunner::RunAllTests(ac, av);
}