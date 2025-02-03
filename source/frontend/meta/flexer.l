%option reentrant
%option nounistd
%option never-interactive
%option noyywrap

%top{
#include "barser.hpp"
#define YY_DECL extern "C" yy::parser::symbol_type yylex(void* yyscanner)
#define YY_EXTRA_TYPE yy::parser::location_type
}

%{
#include <iostream>
#define YY_USER_ACTION yyextra.end.line = yyextra.begin.line; \
    yyextra.end.column = yyextra.begin.column + yyleng; \
    loc = yyextra; \
    yyextra.begin = yyextra.end;
%}

ID [a-z_][a-zA-Z0-9_]*

%%
    auto loc = yy::parser::location_type();

{ID} {
    return yy::parser::make_ID(yytext, loc);
}
"+" {
    return yy::parser::make_PLUS(loc);
}
"*" {
    return yy::parser::make_ASTERIKS(loc);
}
"-" {
    return yy::parser::make_MINUS(loc);
}
"/" {
    return yy::parser::make_SLASH(loc);
}

\n {
    yyextra.begin.line += 1;
    yyextra.begin.column = 1;
}
.
<<EOF>> {
    return yy::parser::make_YYEOF(loc);
}

%%

    const char* ZORT = "zartzurtzartzurt";
