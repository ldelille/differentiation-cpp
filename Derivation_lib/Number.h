

#ifndef TESTCMAKE_Number_H
#define TESTCMAKE_Number_H


#include "Expression.h"

class Number : public Expression {
public:
    Number();
    explicit Number(int value);
    virtual Number* derive(const std::string & var) const override;
    virtual std::ostream& display(std::ostream &out) const override;
    virtual Number* clone() const override;
    Number* simplify() const override;
    const int getValue() const;

private:
    const int value_;
};

#endif /* Number_H_ */
