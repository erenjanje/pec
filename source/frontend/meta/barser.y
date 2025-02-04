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
%token <std::string>TYPE "type identifier"
%token <std::string>CONSTANT "constant identifier"

%token ASTERIKS "*"
%token PLUS "+"
%token MINUS "-"
%token SLASH "/"

%token EQUALS "=="
%token LT "<"
%token GT ">"
%token LE "<="
%token GE ">="
%token NEQUALS "!="

%token NOT "not"
%token AND "and"
%token OR "or"

%token BAND "&"
%token BOR "|"
%token XOR "xor"
%token BNOT "~"

%token ASSIGN "="

%token LPAREN "("
%token RPAREN ")"
%token LBRACK "["
%token RBRACK "]"
%token LBRACE "{"
%token RBRACE "}"

%token LET "let"
%token VAR "var"
%token CONST "const"

%token SEMICOLON ";"

%left CAST
%left "==" "<" ">" "<=" ">=" "!="
%left "and" "or"
%left "+" "-"
%left "*" "/"
%left "&" "|" "xor"
%left UNARY

%nterm <std::string>expression
%nterm statement

%start program

%%

program
    : program statement
    | 
    ;

statement
    : expression ";"
    | "let" ID[id] "=" expression[expr] ";" {
        std::cout << "let " << "(" << $id << ")" << " = " << $expr << "\n";
        @$.begin = @1.begin;
        @$.end = @expr.end;
    }
    | "var" ID[id] "=" expression[expr] ";" {
        std::cout << "var " << "(" << $id << ")" << " = " << $expr << "\n";
        @$.begin = @1.begin;
        @$.end = @expr.end;
    }
    | "const" CONSTANT[id] "=" expression[expr] ";" {
        std::cout << "const " << "(" << $id << ")" << " = " << $expr << "\n";
        @$.begin = @1.begin;
        @$.end = @expr.end;
    }
    ;

expression
    : expression[left] "+" expression[right] {
        $$ = "(" + $left + " + " + $right + ")";
        std::cout << $$ << "\n";
        @$.begin = @left.begin;
        @$.end = @right.end;
    }
    | expression[left] "*" expression[right] {
        $$ = "(" + $left + " * " + $right + ")";
        std::cout << $$ << "\n";
        @$.begin = @left.begin;
        @$.end = @right.end;
    }
    | expression[left] "-" expression[right] {
        $$ = "(" + $left + " - " + $right + ")";
        std::cout << $$ << "\n";
        @$.begin = @left.begin;
        @$.end = @right.end;
    }
    | expression[left] "/" expression[right] {
        $$ = "(" + $left + " / " + $right + ")";
        std::cout << $$ << "\n";
        @$.begin = @left.begin;
        @$.end = @right.end;
    }
    | expression[left] "==" expression[right] {
        $$ = "(" + $left + " == " + $right + ")";
        std::cout << $$ << "\n";
        @$.begin = @left.begin;
        @$.end = @right.end;
    }
    | expression[left] "<" expression[right] {
        $$ = "(" + $left + " < " + $right + ")";
        std::cout << $$ << "\n";
        @$.begin = @left.begin;
        @$.end = @right.end;
    }
    | expression[left] ">" expression[right] {
        $$ = "(" + $left + " > " + $right + ")";
        std::cout << $$ << "\n";
        @$.begin = @left.begin;
        @$.end = @right.end;
    }
    | expression[left] "<=" expression[right] {
        $$ = "(" + $left + " <= " + $right + ")";
        std::cout << $$ << "\n";
        @$.begin = @left.begin;
        @$.end = @right.end;
    }
    | expression[left] ">=" expression[right] {
        $$ = "(" + $left + " >= " + $right + ")";
        std::cout << $$ << "\n";
        @$.begin = @left.begin;
        @$.end = @right.end;
    }
    | expression[left] "!=" expression[right] {
        $$ = "(" + $left + " != " + $right + ")";
        std::cout << $$ << "\n";
        @$.begin = @left.begin;
        @$.end = @right.end;
    }
    | expression[left] "and" expression[right] {
        $$ = "(" + $left + " and " + $right + ")";
        std::cout << $$ << "\n";
        @$.begin = @left.begin;
        @$.end = @right.end;
    }
    | expression[left] "or" expression[right] {
        $$ = "(" + $left + " or " + $right + ")";
        std::cout << $$ << "\n";
        @$.begin = @left.begin;
        @$.end = @right.end;
    }
    | expression[left] "&" expression[right] {
        $$ = "(" + $left + " & " + $right + ")";
        std::cout << $$ << "\n";
        @$.begin = @left.begin;
        @$.end = @right.end;
    }
    | expression[left] "|" expression[right] {
        $$ = "(" + $left + " | " + $right + ")";
        std::cout << $$ << "\n";
        @$.begin = @left.begin;
        @$.end = @right.end;
    }
    | expression[left] "xor" expression[right] {
        $$ = "(" + $left + " xor " + $right + ")";
        std::cout << $$ << "\n";
        @$.begin = @left.begin;
        @$.end = @right.end;
    }
    | "-" expression[expr] %prec UNARY {
        $$ = "(" + std::string("-") + $expr + ")";
        std::cout << $$ << "\n";
        @$.begin = @1.begin;
        @$.end = @expr.end;
    }
    | "not" expression[expr] %prec UNARY {
        $$ = "(" + std::string("not ") + $expr + ")";
        std::cout << $$ << "\n";
        @$.begin = @1.begin;
        @$.end = @expr.end;
    }
    | "~" expression[expr] %prec UNARY {
        $$ = "(" + std::string("~") + $expr + ")";
        std::cout << $$ << "\n";
        @$.begin = @1.begin;
        @$.end = @expr.end;
    }
    | TYPE[type] expression[expr] %prec CAST {
        $$ = "(" + $type + " " + $expr + ")";
        std::cout << $$ << "\n";
        @$.begin = @1.begin;
        @$.end = @expr.end;
    }
    | ID[val] {
        $$ = $val;
        std::cout << $$ << "\n";
        @$ = @val;
    }
    | CONSTANT[val] {
        $$ = $val;
        std::cout << $$ << "\n";
        @$ = @val;
    }
    | "(" expression[expr] ")" {
        $$ = $expr;
        std::cout << $$ << "\n";
        @$.begin = @1.begin;
        @$.end = @3.end;
    }
    ;

%%