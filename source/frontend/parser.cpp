#include "parser.hpp"

#include <iostream>

void yyerror(char const* message) {
    std::cerr << "Parser error: " << message << "\n";
}
