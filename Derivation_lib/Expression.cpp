

#include "Expression.h"


Expression::Expression() {
    nb_instances++;
}
Expression::~Expression() {
    nb_instances--;
}

int Expression::get_nb_instances() {
    return nb_instances;
}

std::ostream& operator <<(std::ostream &out, const Expression &expr) {
    return expr.display(out);
}

int Expression::nb_instances = 0;

