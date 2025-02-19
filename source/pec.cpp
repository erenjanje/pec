#include <iostream>

#include "frontend/flexer.hpp"

int main() {
    auto scanner = yyscan_t();
    yylex_init(&scanner);
    auto loc = pec::parser::location_type();
    const auto filename = std::string("stream");
    loc.begin.initialize(&filename, 1, 1);
    loc.end.initialize(&filename, 1, 1);
    yyset_extra(loc, scanner);
    const auto data = std::string(
        "let x = (Int32 a) + !(b + c);\n"
        "var y = Int64 Float x / g;\n"
        "x & x;"
    );
    const auto buf = yy_scan_bytes(data.data(), data.size(), scanner);
    // yy_switch_to_buffer(buf, scanner);
    auto nodes = std::vector<pec::Child<pec::Statement>>();
    auto parser = pec::parser(scanner, nodes);
    const int value = parser.parse();
    for (auto const& node : nodes) {
        node->print(std::cout, 0);
        std::cout << "\n";
    }
    yy_delete_buffer(buf, scanner);
    yylex_destroy(scanner);
}
