#include "CppUTest/CommandLineTestRunner.h"
#include "../src/include/Scanner.hpp"

TEST_GROUP(HeaderTestGroup){

};

TEST(HeaderTestGroup, HeaderTest){
   

};

int main(int ac, char** av){
   return CommandLineTestRunner::RunAllTests(ac, av);
}