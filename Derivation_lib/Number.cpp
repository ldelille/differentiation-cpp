
#include "Number.h"

Number::Number(int value)
        : value_(value) {
}

Number::Number()
        : Number(0) {
}

Number *Number::derive(const std::string &var) const {
    return new Number(0);
}

std::ostream &Number::display(std::ostream &out) const {
    return out << value_;
}

Number *Number::clone() const {
    return new Number(value_);
}

Number *Number::simplify() const {
    return new Number(value_);
}

const int Number::getValue() const {
    return value_;
}
