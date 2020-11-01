

#ifndef TESTCMAKE_OPERATION_H
#define TESTCMAKE_OPERATION_H


#include <string>
#include "Expression.h"

class Operation: public Expression {
public:
    Operation(const Expression * g, const Expression * d);
    ~Operation() override;
    virtual std::ostream& display(std::ostream &out) const override;
    virtual std::string symbole() const = 0;
    const Expression * op_left() const;
    const Expression * op_right() const;
private:
    const Expression * const op_g;
    const Expression * const op_d;
};

#endif /* OPERATION_H_ */
