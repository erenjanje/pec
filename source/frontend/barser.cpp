#include "barser.hpp"

#include <iostream>

void pec::parser::error(pec::parser::location_type const& loc, std::string const& message) {
    std::cout << "Parser error: " << message << " at " << (*loc.begin.filename) << ":" << loc.begin.line << ":"
              << loc.begin.column << " to " << *(loc.end.filename) << ":" << loc.end.line << ":" << loc.end.column << "\n";
}
