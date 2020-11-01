//
// Created by Louis Delille on 30/10/2020.
//

#include "Operation.h"


Operation::Operation(const Expression *g, const Expression *d)
        : op_g(g), op_d(d) {
}

Operation::~Operation() {
    delete op_g;
    delete op_d;
}

std::ostream &Operation::display(std::ostream &out) const {
    return out << '(' << *op_g << ' ' << symbole() << ' ' << *op_d << ')';
}

const Expression *Operation::op_left() const {
    return op_g;
}

const Expression *Operation::op_right() const {
    return op_d;
}