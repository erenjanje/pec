%option reentrant
%option nounistd
%option never-interactive
%option noyywrap

%top{
#include "barser.hpp"
#define YY_DECL extern "C" int yylex(yy::parser::value_type* value, yy::parser::location_type* loc, void* yyscanner)
#define YY_EXTRA_TYPE yy::parser::location_type
}

%{
#include <iostream>
#define YY_USER_ACTION yyextra.end.line = yyextra.begin.line; \
    yyextra.end.column = yyextra.begin.column + yyleng; \
    *loc = yyextra; \
    yyextra.begin = yyextra.end;
%}

ID [a-z_][a-zA-Z0-9_]*

%%

{ID} {
    std::cout << *loc->begin.filename << ":" << loc->begin.line << ":" << loc->begin.column << "-";
    std::cout << *loc->end.filename << ":" << loc->end.line << ":" << loc->end.column << "\n";
    return yy::parser::token::ID;
}
\n {
    yyextra.begin.line += 1;
    yyextra.begin.column = 1;
}
.

%%

    const char* ZORT = "zartzurtzartzurt";
