

#ifndef TESTCMAKE_ADDITION_H
#define TESTCMAKE_ADDITION_H


#include "Operation.h"

class Addition: public Operation {
public:
    Addition(const Expression * g, const Expression * d);
    virtual Expression* derive(const std::string &var) const override;
    virtual Expression* clone() const override;
    virtual std::string symbole() const override;
    virtual Expression* simplify() const override;
};

#endif /* ADDITION_H_ */
