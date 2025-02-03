#include <iostream>
#include "frontend/flexer.hpp"

int main() {
    int x = yyparse();
    std::cout << "Hello, World!\n";
}
