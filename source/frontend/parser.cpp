#include "parser.hpp"

#include <iostream>
#include <utility>

using namespace pec;

static auto repeat(std::string const& str, int count) -> std::string {
    auto ret = std::string();
    ret.reserve(str.size() * count);
    for (int i = 0; i < count; i++) {
        ret += str;
    }
    return ret;
}

#define INDENT (repeat("    ", indentation))
#define NEXT_INDENT (repeat("    ", indentation + 1))

Type::Type(std::string name) : name(std::move(name)) {}

auto Type::print(std::ostream& os, int) const -> std::ostream& {
    return os << name;
}

IdentifierPattern::IdentifierPattern(Child<Type> type, std::string id) : type(std::move(type)), id(std::move(id)) {}

auto IdentifierPattern::print(std::ostream& os, int indentation) const -> std::ostream& {
    if (type) {
        type->print(os, indentation);
        os << " ";
    }
    return os << id;
}

TuplePattern::TuplePattern(std::vector<Child<Pattern>> elements) : elements(std::move(elements)) {}

auto TuplePattern::print(std::ostream& os, int indentation) const -> std::ostream& {
    os << "(";
    for (size_t i = 0; i < elements.size(); i++) {
        elements[i]->print(os, 0);
        if (i != elements.size() - 1) {
            os << ", ";
        }
    }
    os << ")";
    return os;
}

ExpressionStatement::ExpressionStatement(Child<Expression> expression) : expression(std::move(expression)) {}

auto ExpressionStatement::print(std::ostream& os, int indentation) const -> std::ostream& {
    os << "ExpressionStatement(\n";
    os << NEXT_INDENT;
    expression->print(os, indentation + 1);
    os << "\n" << INDENT << ")";
    return os;
}

VariableDefinition::VariableDefinition(Mutability mutability, Child<Pattern> pattern, Child<Expression> expression)
    : mutability(mutability), pattern(std::move(pattern)), expression(std::move(expression)) {}

auto VariableDefinition::print(std::ostream& os, int indentation) const -> std::ostream& {
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
    pattern->print(os, 0);
    os << " = (\n";
    os << NEXT_INDENT;
    expression->print(os, indentation + 1);
    os << "\n" << INDENT << ")";
    return os;
}

Identifier::Identifier(std::string name) : name(std::move(name)) {}

auto Identifier::print(std::ostream& os, int indentation) const -> std::ostream& {
    return os << "Id(" << name << ")";
}

Binary::Binary(Operator op, Child<Expression> left, Child<Expression> right)
    : op(op), left(std::move(left)), right(std::move(right)) {}

auto Binary::print(std::ostream& os, int indentation) const -> std::ostream& {
    os << "Binop(" << op << ")" << "(\n";
    os << NEXT_INDENT;
    left->print(os, indentation + 1);
    os << "\n";
    os << NEXT_INDENT;
    right->print(os, indentation + 1);
    os << "\n" << INDENT << ")";
    return os;
}

Unary::Unary(Operator op, Child<Expression> expression) : op(op), expression(std::move(expression)) {}

auto Unary::print(std::ostream& os, int indentation) const -> std::ostream& {
    os << "Unop(" << op << ")(\n";
    os << NEXT_INDENT;
    expression->print(os, indentation + 1);
    os << "\n" << INDENT << ")";
    return os;
}

Cast::Cast(Child<Type> type, Child<Expression> expression) : type(std::move(type)), expression(std::move(expression)) {}

auto Cast::print(std::ostream& os, int indentation) const -> std::ostream& {
    os << "Cast(" << type << ")(\n";
    os << NEXT_INDENT;
    expression->print(os, indentation + 1);
    os << "\n" << INDENT << ")";
    return os;
}

auto pec::operator<<(std::ostream& os, Binary::Operator op) -> std::ostream& {
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

auto pec::operator<<(std::ostream& os, Unary::Operator op) -> std::ostream& {
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
