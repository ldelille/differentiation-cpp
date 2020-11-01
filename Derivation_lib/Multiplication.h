
#ifndef TESTCMAKE_MULTIPLICATION_H
#define TESTCMAKE_MULTIPLICATION_H



#include "Operation.h"

class Multiplication: public Operation {
public:
    Multiplication(const Expression * g, const Expression * d);
    virtual Expression* derive(const std::string &var) const override;
    virtual Expression* clone() const override;
    virtual std::string symbole() const override;
    Expression * simplify() const override ;

};

#endif /* MULTIPLICATION_H_ */
