#include "scanner.hpp"
#include <iostream>
#include <fstream>

Scanner::Scanner(std::string filePath){
    this->path = filePath;
    std::cout << "Scanner Created " << filePath  << std::endl;
}

void Scanner::scan(){
    std::cout << "Scanning " << this->path << std::endl;
    std::ifstream file;
    file.open(path);

    if(!file){
        throw std::runtime_error("Could not open file: " + this->path);
    }

    std::string currentLine;
    while (std::getline(file, currentLine)){
        std::cout << currentLine << std::endl;
        extractHeaders(currentLine);
    }
}

int Scanner::extractHeaders(std::string& line){
    std::cout << "Extracting Headers From: " << line << std::endl;
    return 0;
}

std::string Scanner::nextLine(){
    return "Linking Worked";
}