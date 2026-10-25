#include <iostream>

#include "args.hpp"
#include "complex.h"

int main(const int argc, char** argv) {
  ArgumentParser parser{argc, argv};
  Arguments args;
  try {
    args = parser.parse();
  } catch (const ParserException& err) {
    std::cerr << "error: " << err.what() << std::endl;
    return 1;
  }
  std::cout << pow(args.x, args.y) << std::endl;
  return 0;
}
