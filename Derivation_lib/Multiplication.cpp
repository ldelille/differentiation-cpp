

#include "Multiplication.h"
#include "Addition.h"
#include "Number.h"

Multiplication::Multiplication(const Expression *g, const Expression *d)
        : Operation(g, d) {
}

Expression *Multiplication::derive(const std::string &var) const {
    return new Addition(
            new Multiplication(op_left()->derive(var), op_right()->clone()),
            new Multiplication(op_left()->clone(), op_right()->derive(var))
    );
}

Expression *Multiplication::clone() const {
    return new Multiplication(op_left()->clone(), op_right()->clone());
}

std::string Multiplication::symbole() const {
    return "*";
}

Expression *Multiplication::simplify() const {
    auto q = op_left()->simplify();
    auto p = op_right()->simplify();
    if (typeid(*p) == typeid(Number) and typeid(*q) == typeid(Number)) {
        Number *left = {dynamic_cast<Number *>(p)};
        Number *right = {dynamic_cast<Number *>(q)};
        return new Number(left->getValue() * right->getValue());
    } else {
        return new Multiplication(op_left()->simplify(), op_right()->simplify());
    }
}

