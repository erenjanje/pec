#pragma once

#include <iosfwd>
#include <memory>
#include <string>

namespace pec {

template <typename T>
using Child = std::unique_ptr<T>;

template <typename T, typename... Args>
Child<T> make(Args&&... args) {
    return std::make_unique<T>(std::forward<Args>(args)...);
}

struct Expression {
    virtual std::ostream& print(std::ostream& os, int indentation) const = 0;
};

struct Identifier : Expression {
    std::string name;

    Identifier(std::string const& name);
    std::ostream& print(std::ostream& os, int indentation) const override;
};

struct Constant : Expression {
    std::string name;

    Constant(std::string const& name);
    std::ostream& print(std::ostream& os, int indentation) const override;
};

struct Binary : Expression {
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

struct Unary : Expression {
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

struct Cast : Expression {
    std::string type;
    Child<Expression> expression;

    Cast(std::string const& type, Child<Expression> expression);
    std::ostream& print(std::ostream& os, int indentation) const override;
};

}  // namespace pec
