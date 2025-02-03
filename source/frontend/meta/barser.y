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

%token <std::string>ID "identifier"

%token ASTERIKS "*"
%token PLUS "+"
%token MINUS "-"
%token SLASH "/"

%left "+" "-"
%left "*" "/"

%nterm <std::string>expression

%start program

%%

program
    : expression
    | program expression
    ;

expression[ret]
    : expression[left] "+" expression[right] {
        $ret = "(" + $left + " + " + $right + ")";
        std::cout << $ret << "\n";
    }
    | expression[left] "*" expression[right] {
        $ret = "(" + $left + " * " + $right + ")";
        std::cout << $ret << "\n";
    }
    | expression[left] "-" expression[right] {
        $ret = "(" + $left + " - " + $right + ")";
        std::cout << $ret << "\n";
    }
    | expression[left] "/" expression[right] {
        $ret = "(" + $left + " / " + $right + ")";
        std::cout << $ret << "\n";
    }
    | ID[val] {
        $ret = $val;
        std::cout << $ret << "\n";
    }
    ;

%%