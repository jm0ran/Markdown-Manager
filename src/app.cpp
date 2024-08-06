#include <iostream>

extern "C" {
    #include "app2.h" 
};

void log(std::string string){
    std::cout << string << std::endl;
}

int main(int argc, char const *argv[])
{
    log("Hello From C++");
    printHelloWorld();
}