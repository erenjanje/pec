#include "parser.hpp"

#include <iostream>
#include <utility>

static std::string repeat(std::string const& str, int count) {
    auto ret = std::string();
    ret.reserve(str.size() * count);
    for (int i = 0; i < count; i++) {
        ret += str;
    }
    return ret;
}

#define INDENT (repeat("    ", indentation))
#define NEXT_INDENT (repeat("    ", indentation + 1))

pec::Pattern::Pattern(std::string id) : id(std::move(id)) {}

std::ostream& pec::Pattern::print(std::ostream& os, int indentation) const {
    return os << id;
}

pec::ExpressionStatement::ExpressionStatement(Child<Expression> expression) : expression(std::move(expression)) {}

std::ostream& pec::ExpressionStatement::print(std::ostream& os, int indentation) const {
    os << "ExpressionStatement(\n";
    os << NEXT_INDENT;
    expression->print(os, indentation + 1);
    os << "\n" << INDENT << ")";
    return os;
}
pec::VariableDefinition::VariableDefinition(Mutability mutability, Pattern pattern, Child<Expression> expression)
    : mutability(mutability), pattern(std::move(pattern)), expression(std::move(expression)) {}

std::ostream& pec::VariableDefinition::print(std::ostream& os, int indentation) const {
    switch (mutability) {
        case Comptime:
            os << "Comptime ";
            break;
        case Immutable:
            os << "Immutable ";
            break;
        case Mutable:
            os << "Mutable ";
            break;
    }
    pattern.print(os, 0);
    os << " = (\n";
    os << NEXT_INDENT;
    expression->print(os, indentation + 1);
    os << "\n" << INDENT << ")";
    return os;
}

pec::Identifier::Identifier(std::string name) : name(std::move(name)) {}

std::ostream& pec::Identifier::print(std::ostream& os, int indentation) const {
    return os << "Id(" << name << ")";
}

pec::Binary::Binary(Operator op, Child<Expression> left, Child<Expression> right)
    : op(op), left(std::move(left)), right(std::move(right)) {}

std::ostream& pec::Binary::print(std::ostream& os, int indentation) const {
    os << "Binop(" << op << ")" << "(\n";
    os << NEXT_INDENT;
    left->print(os, indentation + 1);
    os << "\n";
    os << NEXT_INDENT;
    right->print(os, indentation + 1);
    os << "\n" << INDENT << ")";
    return os;
}

pec::Unary::Unary(Operator op, Child<Expression> expression) : op(op), expression(std::move(expression)) {}

std::ostream& pec::Unary::print(std::ostream& os, int indentation) const {
    os << "Unop(" << op << ")(\n";
    os << NEXT_INDENT;
    expression->print(os, indentation + 1);
    os << "\n" << INDENT << ")";
    return os;
}

pec::Cast::Cast(std::string type, Child<Expression> expression)
    : type(std::move(type)), expression(std::move(expression)) {}

std::ostream& pec::Cast::print(std::ostream& os, int indentation) const {
    os << "Cast(" << type << ")(\n";
    os << NEXT_INDENT;
    expression->print(os, indentation + 1);
    os << "\n" << INDENT << ")";
    return os;
}

std::ostream& pec::operator<<(std::ostream& os, Binary::Operator op) {
    switch (op) {
        case Binary::Operator::Add:
            return os << "+";
        case Binary::Operator::And:
            return os << "and";
        case Binary::Operator::Band:
            return os << "&";
        case Binary::Operator::Bor:
            return os << "|";
        case Binary::Operator::Divide:
            return os << "/";
        case Binary::Operator::Equals:
            return os << "==";
        case Binary::Operator::GreaterEquals:
            return os << ">=";
        case Binary::Operator::GreaterThan:
            return os << ">";
        case Binary::Operator::LittleEquals:
            return os << "<=";
        case Binary::Operator::LittleThan:
            return os << "<";
        case Binary::Operator::Multiply:
            return os << "*";
        case Binary::Operator::NotEquals:
            return os << "!=";
        case Binary::Operator::Or:
            return os << "or";
        case Binary::Operator::Subtract:
            return os << "-";
        case Binary::Operator::Xor:
            return os << "xor";
    }
    return os;
}

std::ostream& pec::operator<<(std::ostream& os, Unary::Operator op) {
    switch (op) {
        case Unary::Operator::Bnot:
            return os << "~";
        case Unary::Operator::Negate:
            return os << "-";
        case Unary::Operator::Not:
            return os << "not";
    }
    return os;
}
