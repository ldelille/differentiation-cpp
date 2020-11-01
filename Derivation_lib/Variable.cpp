
#include "Variable.h"
#include "Number.h"

Variable::Variable(const std::string &nom)
        : nom_(nom){
}


Expression* Variable::derive(const std::string &var) const {
    if (nom_ == var) {
        return new Number(1);
    } else {
        return new Number(0);
    }
}

std::ostream& Variable::display(std::ostream &out) const {
    return out << nom_;
}

Expression* Variable::clone() const {
    return new Variable(nom_);
}

Expression* Variable::simplify() const {
    return new Variable(nom_);
}
