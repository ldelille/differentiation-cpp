

#ifndef TESTCMAKE_VARIABLE_H
#define TESTCMAKE_VARIABLE_H


#include <string>
#include "Expression.h"

class Variable: public Expression {
public:
    explicit Variable(const std::string & nom);
    virtual Expression* derive(const std::string &var) const override;
    virtual std::ostream& display(std::ostream &out) const override;
    virtual Expression* clone() const override;
    virtual Expression* simplify() const override;

private:
    const std::string nom_;
};


#endif //TESTCMAKE_VARIABLE_H
