%require "3.2"
%language "c++"
%define parse.error verbose
%locations
%define api.value.type variant
%define api.token.constructor
%param {void* yyscanner}

%code {
extern "C" yy::parser::symbol_type yylex(void*);
#include <iostream>
}

%token <std::string>ID

%start program

%%

program
    : ID[val] {
        std::cout << *@val.begin.filename << ":" << @val.begin.line << ":" << @val.begin.column << "-";
        std::cout << *@val.end.filename << ":" << @val.end.line << ":" << @val.end.column << "\t";
        std::cout << $val << "\n";
    }
    | ID[val] program {
        std::cout << *@val.begin.filename << ":" << @val.begin.line << ":" << @val.begin.column << "-";
        std::cout << *@val.end.filename << ":" << @val.end.line << ":" << @val.end.column << "\t";
        std::cout << $val << "\n";
    }
    ;

%%