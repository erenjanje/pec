#include <iostream>

#include "frontend/flexer.hpp"

auto main() -> int {
    auto scanner = yyscan_t();
    yylex_init(&scanner);
    auto loc = pec::parser::location_type();
    const auto filename = std::string("stream");
    loc.begin.initialize(&filename, 1, 1);
    loc.end.initialize(&filename, 1, 1);
    yyset_extra(loc, scanner);
    const auto data = std::string(
        // "let $ZORT = a;"
        // "let x = (Int32 a) + !(b + c);\n"
        // "var y = Int64 Float $X / g;\n"
        // "x & x;\n"
        // "let (a, b) = x;"
        // "let ((a, b), ((c, d), e, f, g)) = z;"
        // "let ((a, Int32 b), ((c, d), e, f, g)) = {\n"
        // "let a = y;\n"
        // "let b = z;\n"
        // "};"
        "if(true) { a; } else if(false) { b; } - b;"
    );

    const auto buf = yy_scan_bytes(data.data(), static_cast<int>(data.size()), scanner);
    // yy_switch_to_buffer(buf, scanner);
    auto nodes = std::vector<pec::Child<pec::Statement>>();
    auto parser = pec::parser(scanner, nodes);
    const int result = parser.parse();
    if (result == 0) {
        for (auto const& node : nodes) {
            node->print(std::cout, 0);
            std::cout << "\n";
        }
    }
    yy_delete_buffer(buf, scanner);
    yylex_destroy(scanner);
    return result;
}
