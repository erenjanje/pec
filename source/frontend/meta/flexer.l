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

identifier_inner [a-zA-Z0-9]*
identifier [a-z_][a-zA-Z0-9_]*
type [A-Z]{identifier_inner}[a-z]{identifier_inner}
constant [A-Z][A-Z0-9_]*

%%
    auto loc = yy::parser::location_type();

"let" { return yy::parser::make_LET(loc); }
"var" { return yy::parser::make_VAR(loc); }
"const" { return yy::parser::make_CONST(loc); }

"+" { return yy::parser::make_PLUS(loc); }
"*" { return yy::parser::make_ASTERIKS(loc); }
"-" { return yy::parser::make_MINUS(loc); }
"/" { return yy::parser::make_SLASH(loc); }

"==" { return yy::parser::make_EQUALS(loc); }
"<" { return yy::parser::make_LT(loc); }
">" { return yy::parser::make_GT(loc); }
"<=" { return yy::parser::make_LE(loc); }
">=" { return yy::parser::make_GE(loc); }
"!=" { return yy::parser::make_NEQUALS(loc); }

"not" { return yy::parser::make_NOT(loc); }
"!" { return yy::parser::make_NOT(loc); }
"and" { return yy::parser::make_AND(loc); }
"&&" { return yy::parser::make_AND(loc); }
"or" { return yy::parser::make_OR(loc); }
"||" { return yy::parser::make_OR(loc); }

"&" { return yy::parser::make_BAND(loc); }
"|" { return yy::parser::make_BOR(loc); }
"xor" { return yy::parser::make_XOR(loc); }
"~" { return yy::parser::make_BNOT(loc); }

"=" { return yy::parser::make_ASSIGN(loc); }

"(" { return yy::parser::make_LPAREN(loc); }
")" { return yy::parser::make_RPAREN(loc); }
"[" { return yy::parser::make_LBRACK(loc); }
"]" { return yy::parser::make_RBRACK(loc); }
"{" { return yy::parser::make_LBRACE(loc); }
"}" { return yy::parser::make_RBRACE(loc); }

";" { return yy::parser::make_SEMICOLON(loc); }

{identifier} { return yy::parser::make_ID(yytext, loc); }
{type} { return yy::parser::make_TYPE(yytext, loc); }
{constant} { return yy::parser::make_CONSTANT(yytext, loc); }

\n {
    yyextra.begin.line += 1;
    yyextra.begin.column = 1;
}
<<EOF>> {
    YY_USER_ACTION;
    return yy::parser::make_YYEOF(loc);
}
.

%%

    const char* ZORT = "zartzurtzartzurt";
