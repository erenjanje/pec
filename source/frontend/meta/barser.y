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
namespace pec {
uintmax_t makeInteger(std::string const& s, int base);
}
}

%code {
extern "C" pec::parser::symbol_type yylex(void*);
#include <iostream>
}

%token <std::string>ID "identifier"
%token <std::string>TYPE "type identifier"
%token <std::string>CONSTANT "constant identifier"

%token <uintmax_t>INTEGER "integer"
%token <long double>REAL "real number"

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

%token IF "if"
%token ELSE "else"

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

%nonassoc ")"
%nonassoc "else"

%nterm <Child<Statement>>statement
%nterm <std::vector<Child<Statement>>>statement_list
%nterm <std::vector<Child<Statement>>>program

%nterm <Child<Type>>type
%nterm <TuplePattern>pattern_list
%nterm <Child<Pattern>>top_level_pattern
%nterm <Child<Pattern>>pattern

%nterm <Child<Expression>>top_level_expression
%nterm <Child<Expression>>block_expression
%nterm <Child<Expression>>expression

%start program

%%

program
    : statement_list[statements] { ret = std::move($statements); }
    ;

statement_list
    : statement_list[prev] statement[next] {
        $$ = std::move($prev);
        $$.emplace_back(std::move($next));
        @$.begin = @prev.begin;
        @$.end = @next.end;
    }
    | %empty {}
    ;

type
    : TYPE[name] {
        $$ = make<Type>(std::move($name));
        @$ = @name;
    }
    ;

statement
    : top_level_expression[expr] ";" {
        $$ = make<ExpressionStatement>(std::move($expr));
        @$.begin = @1.begin;
        @$.end = @expr.end;
    }
    | "let" top_level_pattern[pat] "=" expression[expr] ";" {
        $$ = make<VariableDefinition>(VariableDefinition::Mutability::Immutable, std::move($pat), std::move($expr));
        @$.begin = @1.begin;
        @$.end = @expr.end;
    }
    | "var" top_level_pattern[pat] "=" expression[expr] ";" {
        $$ = make<VariableDefinition>(VariableDefinition::Mutability::Mutable, std::move($pat), std::move($expr));
        @$.begin = @1.begin;
        @$.end = @expr.end;
    }
    | block_expression[expr] {
        $$ = make<ExpressionStatement>(std::move($expr));
        @$ = @expr;
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
    | INTEGER[val] {
        $$ = make<Integer>($val);
        @$ = @val;
    }
    | "(" expression[expr] ")" {
        $$ = std::move($expr);
        @$.begin = @1.begin;
        @$.end = @3.end;
    }
    | block_expression[expr] {
        $$ = std::move($expr);
        @$ = @expr;
    }
    ;

top_level_expression
    : top_level_expression[left] "+" top_level_expression[right] {
        $$ = make<Binary>(Binary::Operator::Add, std::move($left), std::move($right));
        @$.begin = @left.begin;
        @$.end = @right.end;
    }
    | top_level_expression[left] "*" top_level_expression[right] {
        $$ = make<Binary>(Binary::Operator::Multiply, std::move($left), std::move($right));
        @$.begin = @left.begin;
        @$.end = @right.end;
    }
    | top_level_expression[left] "-" top_level_expression[right] {
        $$ = make<Binary>(Binary::Operator::Subtract, std::move($left), std::move($right));
        @$.begin = @left.begin;
        @$.end = @right.end;
    }
    | top_level_expression[left] "/" top_level_expression[right] {
        $$ = make<Binary>(Binary::Operator::Divide, std::move($left), std::move($right));
        @$.begin = @left.begin;
        @$.end = @right.end;
    }
    | top_level_expression[left] "==" top_level_expression[right] {
        $$ = make<Binary>(Binary::Operator::Equals, std::move($left), std::move($right));
        @$.begin = @left.begin;
        @$.end = @right.end;
    }
    | top_level_expression[left] "<" top_level_expression[right] {
        $$ = make<Binary>(Binary::Operator::LittleThan, std::move($left), std::move($right));
        @$.begin = @left.begin;
        @$.end = @right.end;
    }
    | top_level_expression[left] ">" top_level_expression[right] {
        $$ = make<Binary>(Binary::Operator::GreaterThan, std::move($left), std::move($right));
        @$.begin = @left.begin;
        @$.end = @right.end;
    }
    | top_level_expression[left] "<=" top_level_expression[right] {
        $$ = make<Binary>(Binary::Operator::LittleEquals, std::move($left), std::move($right));
        @$.begin = @left.begin;
        @$.end = @right.end;
    }
    | top_level_expression[left] ">=" top_level_expression[right] {
        $$ = make<Binary>(Binary::Operator::GreaterEquals, std::move($left), std::move($right));
        @$.begin = @left.begin;
        @$.end = @right.end;
    }
    | top_level_expression[left] "!=" top_level_expression[right] {
        $$ = make<Binary>(Binary::Operator::NotEquals, std::move($left), std::move($right));
        @$.begin = @left.begin;
        @$.end = @right.end;
    }
    | top_level_expression[left] "and" top_level_expression[right] {
        $$ = make<Binary>(Binary::Operator::And, std::move($left), std::move($right));
        @$.begin = @left.begin;
        @$.end = @right.end;
    }
    | top_level_expression[left] "or" top_level_expression[right] {
        $$ = make<Binary>(Binary::Operator::Or, std::move($left), std::move($right));
        @$.begin = @left.begin;
        @$.end = @right.end;
    }
    | top_level_expression[left] "&" top_level_expression[right] {
        $$ = make<Binary>(Binary::Operator::Band, std::move($left), std::move($right));
        @$.begin = @left.begin;
        @$.end = @right.end;
    }
    | top_level_expression[left] "|" top_level_expression[right] {
        $$ = make<Binary>(Binary::Operator::Bor, std::move($left), std::move($right));
        @$.begin = @left.begin;
        @$.end = @right.end;
    }
    | top_level_expression[left] "xor" top_level_expression[right] {
        $$ = make<Binary>(Binary::Operator::Xor, std::move($left), std::move($right));
        @$.begin = @left.begin;
        @$.end = @right.end;
    }
    | "-" top_level_expression[expr] %prec UNARY {
        $$ = make<Unary>(Unary::Operator::Negate, std::move($expr));
        @$.begin = @1.begin;
        @$.end = @expr.end;
    }
    | "not" top_level_expression[expr] %prec UNARY {
        $$ = make<Unary>(Unary::Operator::Not, std::move($expr));
        @$.begin = @1.begin;
        @$.end = @expr.end;
    }
    | "~" top_level_expression[expr] %prec UNARY {
        $$ = make<Unary>(Unary::Operator::Bnot, std::move($expr));
        @$.begin = @1.begin;
        @$.end = @expr.end;
    }
    | type[t] top_level_expression[expr] %prec CAST {
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
    | INTEGER[val] {
        $$ = make<Integer>($val);
        @$ = @val;
    }
    | "(" expression[expr] ")" {
        $$ = std::move($expr);
        @$.begin = @1.begin;
        @$.end = @3.end;
    }
    ;

block_expression
    : "{" statement_list[statements] "}" {
        $$ = make<Block>(std::move($statements));
        @$.begin = @1.begin;
        @$.end = @3.end;
    }
    | "if" "(" expression[condition] ")" statement[then] {
        $$ = make<Conditional>(std::move($condition), std::move($then), nullptr);
        @$.begin = @1.begin;
        @$.end = @then.end;
    }
    | "if" "(" expression[condition] ")" statement[then] "else" statement[otherwise] {
        $$ = make<Conditional>(std::move($condition), std::move($then), std::move($otherwise));
        @$.begin = @1.begin;
        @$.end = @otherwise.end;
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

top_level_pattern
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

%%