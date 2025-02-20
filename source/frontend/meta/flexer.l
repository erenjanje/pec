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

leading_decimal_digit [1-9]
decimal_digit [0-9\']

leading_binary_digit [0-1]
binary_digit [0-1\']

leading_hex_digit [0-9a-fA-F]
hex_digit [0-9a-fA-F\']

leading_octal_digit [0-7]
octal_digit [0-7\']

decimal_integer {leading_decimal_digit}{decimal_digit}*
binary_integer "0b"{leading_binary_digit}{binary_digit}*
hex_integer "0x"{leading_hex_digit}{hex_digit}*
octal_integer "0o"{leading_octal_digit}{octal_digit}*

%%
    auto loc = pec::parser::location_type();

"if" { return pec::parser::make_IF(loc); }
"else" { return pec::parser::make_ELSE(loc); }

"let" { return pec::parser::make_LET(loc); }
"var" { return pec::parser::make_VAR(loc); }
"const" { return pec::parser::make_CONST(loc); }

"int8" { return pec::parser::make_TYPE("int8", loc); }
"uint8" { return pec::parser::make_TYPE("uint8", loc); }
"int16" { return pec::parser::make_TYPE("int16", loc); }
"uint16" { return pec::parser::make_TYPE("uint16", loc); }
"int32" { return pec::parser::make_TYPE("int32", loc); }
"uint32" { return pec::parser::make_TYPE("uint32", loc); }
"int64" { return pec::parser::make_TYPE("int64", loc); }
"uint64" { return pec::parser::make_TYPE("uint64", loc); }
"intsize" { return pec::parser::make_TYPE("intsize", loc); }
"uintsize" { return pec::parser::make_TYPE("uintsize", loc); }

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
"," { return pec::parser::make_COMMA(loc); }

{constant} { return pec::parser::make_CONSTANT(yytext, loc); }
{identifier} { return pec::parser::make_ID(yytext, loc); }
{type} { return pec::parser::make_TYPE(yytext, loc); }

{decimal_integer} { return pec::parser::make_INTEGER(pec::makeInteger(yytext, 10), loc); }
{binary_integer} { return pec::parser::make_INTEGER(pec::makeInteger(yytext + 2, 2), loc); }
{hex_integer} { return pec::parser::make_INTEGER(pec::makeInteger(yytext + 2, 16), loc); }
{octal_integer} { return pec::parser::make_INTEGER(pec::makeInteger(yytext + 2, 8), loc); }

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
