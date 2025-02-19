#pragma once

#include <iosfwd>
#include <memory>
#include <string>
#include <utility>
#include <vector>

namespace pec {

template <typename T>
using Child = std::unique_ptr<T>;

struct Pattern {
    std::string id;

    Pattern() = default;
    explicit Pattern(std::string id);
    std::ostream& print(std::ostream& os, int indentation) const;
};

struct Expression;
struct ExpressionStatement;

template <typename T, typename... Args>
Child<T> make(Args&&... args) {
    return std::make_unique<T>(std::forward<Args>(args)...);
}

struct ParserNode {
    virtual ~ParserNode() = default;
    virtual std::ostream& print(std::ostream& os, int indentation) const = 0;
};

struct Statement : ParserNode {};

struct ExpressionStatement final : Statement {
    Child<Expression> expression;

    explicit ExpressionStatement(Child<Expression> expression);
    std::ostream& print(std::ostream& os, int indentation) const override;
};

struct VariableDefinition final : Statement {
    enum Mutability {
        Comptime,
        Immutable,
        Mutable,
    } mutability;
    Pattern pattern;
    Child<Expression> expression;

    explicit VariableDefinition(Mutability mutability, Pattern pattern, Child<Expression> expression);
    std::ostream& print(std::ostream& os, int indentation) const override;
};

struct Expression : ParserNode {};

struct Identifier final : Expression {
    std::string name;

    explicit Identifier(std::string name);
    std::ostream& print(std::ostream& os, int indentation) const override;
};

struct Binary final : Expression {
    enum class Operator {
        Add,
        Subtract,
        Multiply,
        Divide,
        Equals,
        LittleThan,
        GreaterThan,
        LittleEquals,
        GreaterEquals,
        NotEquals,
        And,
        Or,
        Band,
        Bor,
        Xor,
    } op;
    Child<Expression> left;
    Child<Expression> right;

    Binary(Operator op, Child<Expression> left, Child<Expression> right);
    std::ostream& print(std::ostream& os, int indentation) const override;
};
std::ostream& operator<<(std::ostream& os, Binary::Operator op);

struct Unary final : Expression {
    enum class Operator {
        Negate,
        Not,
        Bnot,
    } op;
    Child<Expression> expression;

    Unary(Operator op, Child<Expression> expression);
    std::ostream& print(std::ostream& os, int indentation) const override;
};
std::ostream& operator<<(std::ostream& os, Unary::Operator op);

struct Cast final : Expression {
    std::string type;
    Child<Expression> expression;

    Cast(std::string type, Child<Expression> expression);
    std::ostream& print(std::ostream& os, int indentation) const override;
};

struct Block final : Expression {
    std::vector<Child<Expression>> statements;
    std::ostream& print(std::ostream& os, int indentation) const override;
};

}  // namespace pec
