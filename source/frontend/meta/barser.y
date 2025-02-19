%require "3.2"
%language "c++"

%define parse.error detailed
%define parse.lac full
%locations
%define api.value.type variant
%define api.namespace {pec}
%define api.token.constructor
%param {void* yyscanner}
%parse-param {std::vector<pec::Child<pec::Statement>>& ret}

%code requires {
#include "frontend/parser.hpp"
}

%code {
extern "C" pec::parser::symbol_type yylex(void*);
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

%token COMMA ","
%token SEMICOLON ";"

%left CAST
%left "==" "<" ">" "<=" ">=" "!="
%left "and" "or"
%left "+" "-"
%left "*" "/"
%left "&" "|" "xor"
%left UNARY

%nterm <Child<Type>>type
%nterm <TuplePattern>pattern_list
%nterm <Child<Pattern>>general_pattern
%nterm <Child<Pattern>>pattern
%nterm <std::vector<Child<Statement>>>program
%nterm <Child<Expression>>expression
%nterm <Child<Statement>>statement

%start program

%%

program
    : program[others] statement[stmt] {
        ret.emplace_back(std::move($stmt));
    }
    | %empty {
    }
    ;

pattern_list
    : pattern_list[list] "," pattern[pat] {
        $$ = std::move($list);
        $$.elements.emplace_back(std::move($pat));
        @$.begin = @list.begin;
        @$.end = @pat.end;
    }
    | pattern[pat] {
        $$.elements.emplace_back(std::move($pat));
        @$ = @pat;
    }
    ;

pattern
    : ID[id] {
        $$ = make<IdentifierPattern>(nullptr, std::move($id));
        @$ = @id;
    }
    | CONSTANT[id] {
        $$ = make<IdentifierPattern>(nullptr, std::move($id));
        @$ = @id;
    }
    | TYPE[type] ID[id] %prec CAST {
        $$ = make<IdentifierPattern>(make<Type>(std::move($type)), std::move($id));
        @$.begin = @type.begin;
        @$.end = @id.end;
    }
    | "(" pattern_list[list] ")" {
        $$ = make<TuplePattern>(std::move($list));
        @$.begin = @1.begin;
        @$.end = @3.end;
    }
    ;

general_pattern
    : ID[id] {
        $$ = make<IdentifierPattern>(nullptr, std::move($id));
        @$ = @id;
    }
    | CONSTANT[id] {
        $$ = make<IdentifierPattern>(nullptr, std::move($id));
        @$ = @id;
    }
    | "(" pattern_list[list] ")" {
        $$ = make<TuplePattern>(std::move($list));
        @$.begin = @1.begin;
        @$.end = @3.end;
    }
    ;

type
    : TYPE[name] {
        $$ = make<Type>(std::move($name));
        @$ = @name;
    }
    ;

statement
    : expression[expr] ";" {
        $$ = make<ExpressionStatement>(std::move($expr));
        @$.begin = @1.begin;
        @$.end = @expr.end;
    }
    | "let" general_pattern[pat] "=" expression[expr] ";" {
        $$ = make<VariableDefinition>(VariableDefinition::Mutability::Immutable, std::move($pat), std::move($expr));
        @$.begin = @1.begin;
        @$.end = @expr.end;
    }
    | "var" general_pattern[pat] "=" expression[expr] ";" {
        $$ = make<VariableDefinition>(VariableDefinition::Mutability::Mutable, std::move($pat), std::move($expr));
        @$.begin = @1.begin;
        @$.end = @expr.end;
    }
    ;

expression
    : expression[left] "+" expression[right] {
        $$ = make<Binary>(Binary::Operator::Add, std::move($left), std::move($right));
        @$.begin = @left.begin;
        @$.end = @right.end;
    }
    | expression[left] "*" expression[right] {
        $$ = make<Binary>(Binary::Operator::Multiply, std::move($left), std::move($right));
        @$.begin = @left.begin;
        @$.end = @right.end;
    }
    | expression[left] "-" expression[right] {
        $$ = make<Binary>(Binary::Operator::Subtract, std::move($left), std::move($right));
        @$.begin = @left.begin;
        @$.end = @right.end;
    }
    | expression[left] "/" expression[right] {
        $$ = make<Binary>(Binary::Operator::Divide, std::move($left), std::move($right));
        @$.begin = @left.begin;
        @$.end = @right.end;
    }
    | expression[left] "==" expression[right] {
        $$ = make<Binary>(Binary::Operator::Equals, std::move($left), std::move($right));
        @$.begin = @left.begin;
        @$.end = @right.end;
    }
    | expression[left] "<" expression[right] {
        $$ = make<Binary>(Binary::Operator::LittleThan, std::move($left), std::move($right));
        @$.begin = @left.begin;
        @$.end = @right.end;
    }
    | expression[left] ">" expression[right] {
        $$ = make<Binary>(Binary::Operator::GreaterThan, std::move($left), std::move($right));
        @$.begin = @left.begin;
        @$.end = @right.end;
    }
    | expression[left] "<=" expression[right] {
        $$ = make<Binary>(Binary::Operator::LittleEquals, std::move($left), std::move($right));
        @$.begin = @left.begin;
        @$.end = @right.end;
    }
    | expression[left] ">=" expression[right] {
        $$ = make<Binary>(Binary::Operator::GreaterEquals, std::move($left), std::move($right));
        @$.begin = @left.begin;
        @$.end = @right.end;
    }
    | expression[left] "!=" expression[right] {
        $$ = make<Binary>(Binary::Operator::NotEquals, std::move($left), std::move($right));
        @$.begin = @left.begin;
        @$.end = @right.end;
    }
    | expression[left] "and" expression[right] {
        $$ = make<Binary>(Binary::Operator::And, std::move($left), std::move($right));
        @$.begin = @left.begin;
        @$.end = @right.end;
    }
    | expression[left] "or" expression[right] {
        $$ = make<Binary>(Binary::Operator::Or, std::move($left), std::move($right));
        @$.begin = @left.begin;
        @$.end = @right.end;
    }
    | expression[left] "&" expression[right] {
        $$ = make<Binary>(Binary::Operator::Band, std::move($left), std::move($right));
        @$.begin = @left.begin;
        @$.end = @right.end;
    }
    | expression[left] "|" expression[right] {
        $$ = make<Binary>(Binary::Operator::Bor, std::move($left), std::move($right));
        @$.begin = @left.begin;
        @$.end = @right.end;
    }
    | expression[left] "xor" expression[right] {
        $$ = make<Binary>(Binary::Operator::Xor, std::move($left), std::move($right));
        @$.begin = @left.begin;
        @$.end = @right.end;
    }
    | "-" expression[expr] %prec UNARY {
        $$ = make<Unary>(Unary::Operator::Negate, std::move($expr));
        @$.begin = @1.begin;
        @$.end = @expr.end;
    }
    | "not" expression[expr] %prec UNARY {
        $$ = make<Unary>(Unary::Operator::Not, std::move($expr));
        @$.begin = @1.begin;
        @$.end = @expr.end;
    }
    | "~" expression[expr] %prec UNARY {
        $$ = make<Unary>(Unary::Operator::Bnot, std::move($expr));
        @$.begin = @1.begin;
        @$.end = @expr.end;
    }
    | type[t] expression[expr] %prec CAST {
        $$ = make<Cast>(std::move($t), std::move($expr));
        @$.begin = @t.begin;
        @$.end = @expr.end;
    }
    | ID[val] {
        $$ = make<Identifier>($val);
        @$ = @val;
    }
    | CONSTANT[val] {
        $$ = make<Identifier>($val);
        @$ = @val;
    }
    | "(" expression[expr] ")" {
        $$ = std::move($expr);
        @$.begin = @1.begin;
        @$.end = @3.end;
    }
    ;

%%