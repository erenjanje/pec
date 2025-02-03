%language "c++"
%define parse.error verbose
%locations
%param {void* yyscanner}

%code {
extern "C" int yylex(yy::parser::value_type*, yy::parser::location_type*, void*);
#include <iostream>
}

%token ID

%start program

%%

program
    : ID[val]
    | ID[val] program
    ;

%%