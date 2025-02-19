#pragma once

#include <iosfwd>
#include <memory>
#include <string>
#include <utility>
#include <vector>

namespace pec {

template <typename T>
using Child = std::unique_ptr<T>;

template <typename T, typename... Args>
Child<T> make(Args&&... args) {
    return std::make_unique<T>(std::forward<Args>(args)...);
}

struct Expression;
struct ExpressionStatement;

struct ParserNode {
    virtual ~ParserNode() = default;
    virtual std::ostream& print(std::ostream& os, int indentation) const = 0;
};

////////////////////////////////////////////

struct Type {
    std::string name;

    Type() = default;
    explicit Type(std::string name);
    std::ostream& print(std::ostream& os, int indentation) const;

    Type(Type&&) = default;
    Type& operator=(Type&&) = default;
    Type(Type const&) = delete;
    Type& operator=(Type const&) = delete;
    ~Type() = default;
};

////////////////////////////////////////////

struct Pattern {
    virtual ~Pattern() = default;
    virtual std::ostream& print(std::ostream& os, int indentation) const = 0;
};

struct IdentifierPattern final : Pattern {
    Child<Type> type;
    std::string id;

    IdentifierPattern() = default;
    explicit IdentifierPattern(Child<Type> type, std::string id);
    std::ostream& print(std::ostream& os, int indentation) const override;

    IdentifierPattern(IdentifierPattern&&) = default;
    IdentifierPattern& operator=(IdentifierPattern&&) = default;
    IdentifierPattern(const IdentifierPattern&) = default;
    IdentifierPattern& operator=(const IdentifierPattern&) = default;
};

struct TuplePattern final : Pattern {
    std::vector<Child<Pattern>> elements;

    TuplePattern() = default;
    explicit TuplePattern(std::vector<Child<Pattern>> elements);
    std::ostream& print(std::ostream& os, int indentation) const override;

    TuplePattern(TuplePattern&&) = default;
    TuplePattern& operator=(TuplePattern&&) = default;
    TuplePattern(const TuplePattern&) = default;
    TuplePattern& operator=(const TuplePattern&) = default;
};

///////////////////////////////////////////

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
    Child<Pattern> pattern;
    Child<Expression> expression;

    explicit VariableDefinition(Mutability mutability, Child<Pattern> pattern, Child<Expression> expression);
    std::ostream& print(std::ostream& os, int indentation) const override;
};

/////////////////////////////////////////////

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
    Child<Type> type;
    Child<Expression> expression;

    Cast(Child<Type> type, Child<Expression> expression);
    std::ostream& print(std::ostream& os, int indentation) const override;
};

struct Block final : Expression {
    std::vector<Child<Statement>> statements;

    explicit Block(std::vector<Child<Statement>> statements);
    std::ostream& print(std::ostream& os, int indentation) const override;
};

}  // namespace pec
