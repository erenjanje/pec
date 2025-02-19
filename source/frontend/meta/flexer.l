%option reentrant
%option nounistd
%option never-interactive
%option noyywrap

%top{
#include "barser.hpp"
#define YY_DECL extern "C" pec::parser::symbol_type yylex(void* yyscanner)
#define YY_EXTRA_TYPE pec::parser::location_type
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
constant "$"[a-zA-Z_][a-zA-Z0-9_]*

%%
    auto loc = pec::parser::location_type();

"let" { return pec::parser::make_LET(loc); }
"var" { return pec::parser::make_VAR(loc); }
"const" { return pec::parser::make_CONST(loc); }

"+" { return pec::parser::make_PLUS(loc); }
"*" { return pec::parser::make_ASTERIKS(loc); }
"-" { return pec::parser::make_MINUS(loc); }
"/" { return pec::parser::make_SLASH(loc); }

"==" { return pec::parser::make_EQUALS(loc); }
"<" { return pec::parser::make_LT(loc); }
">" { return pec::parser::make_GT(loc); }
"<=" { return pec::parser::make_LE(loc); }
">=" { return pec::parser::make_GE(loc); }
"!=" { return pec::parser::make_NEQUALS(loc); }

"not" { return pec::parser::make_NOT(loc); }
"!" { return pec::parser::make_NOT(loc); }
"and" { return pec::parser::make_AND(loc); }
"&&" { return pec::parser::make_AND(loc); }
"or" { return pec::parser::make_OR(loc); }
"||" { return pec::parser::make_OR(loc); }

"&" { return pec::parser::make_BAND(loc); }
"|" { return pec::parser::make_BOR(loc); }
"xor" { return pec::parser::make_XOR(loc); }
"~" { return pec::parser::make_BNOT(loc); }

"=" { return pec::parser::make_ASSIGN(loc); }

"(" { return pec::parser::make_LPAREN(loc); }
")" { return pec::parser::make_RPAREN(loc); }
"[" { return pec::parser::make_LBRACK(loc); }
"]" { return pec::parser::make_RBRACK(loc); }
"{" { return pec::parser::make_LBRACE(loc); }
"}" { return pec::parser::make_RBRACE(loc); }

";" { return pec::parser::make_SEMICOLON(loc); }

{constant} { return pec::parser::make_CONSTANT(yytext, loc); }
{identifier} { return pec::parser::make_ID(yytext, loc); }
{type} { return pec::parser::make_TYPE(yytext, loc); }

\n {
    yyextra.begin.line += 1;
    yyextra.begin.column = 1;
}
<<EOF>> {
    YY_USER_ACTION;
    return pec::parser::make_YYEOF(loc);
}
.

%%

    const char* ZORT = "zartzurtzartzurt";
