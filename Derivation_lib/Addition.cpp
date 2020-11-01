

#include "Addition.h"
#include "Number.h"


Addition::Addition(const Expression *g, const Expression *d)
        : Operation(g, d) {
}

Expression *Addition::derive(const std::string &var) const {
    return new Addition(op_left()->derive(var), op_right()->derive(var));
}

Expression *Addition::clone() const {
    return new Addition(op_left()->clone(), op_right()->clone());
}

std::string Addition::symbole() const {
    return "+";
}

Expression *Addition::simplify() const {
    auto p = op_right()->simplify();
    auto q = op_left()->simplify();
    if (typeid(*p) == typeid(Number) and typeid(*q) == typeid(Number)) {
        Number *left = {dynamic_cast<Number *>(p)};
        Number *right = {dynamic_cast<Number *>(q)};
        return new Number(left->getValue() + right->getValue());
    } else {
        return new Addition(op_left()->simplify(), op_right()->simplify());
    }
}
