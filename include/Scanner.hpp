#pragma once

#include <string>

class Scanner {
public:
  // Variables

  // Methods
  Scanner(std::string filePath);
  virtual ~Scanner() = default;

  void scan();

  // Returns next line
  std::string nextLine();

  // Checks for headers on the passed line, handles h1-h6
  int extractHeaders(std::string &line);

private:
  // Variables
  std::string path;

  // Methods
};
