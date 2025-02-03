#include <iostream>

#include "frontend/flexer.hpp"

int main() {
    auto scanner = yyscan_t();
    yylex_init(&scanner);
    auto loc = yy::parser::location_type();
    auto filename = std::string("stream");
    loc.begin.initialize(&filename, 1, 1);
    loc.end.initialize(&filename, 1, 1);
    yyset_extra(loc, scanner);
    auto data = std::string("zurt - bort / hart + kurt * zart");
    auto buf = yy_scan_bytes(data.data(), data.size(), scanner);
    // yy_switch_to_buffer(buf, scanner);
    auto parser = yy::parser(scanner);
    int x = parser.parse();
    std::cout << "Result: " << x << "\n";
    yy_delete_buffer(buf, scanner);
    yylex_destroy(scanner);
}
