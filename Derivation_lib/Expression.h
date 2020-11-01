

#ifndef TESTCMAKE_EXPRESSION_H
#define TESTCMAKE_EXPRESSION_H

#include <iostream>
#include <string>

class Expression {
public:
    Expression();
    virtual ~Expression();
    virtual Expression * derive(const std::string & var) const = 0;
    virtual std::ostream & display(std::ostream & out) const = 0;
    virtual Expression * clone() const = 0;
    virtual Expression * simplify() const = 0;
    static int get_nb_instances();
private:
    static int nb_instances;
};

std::ostream & operator << (std::ostream & out, const Expression & expr);



#endif //TESTCMAKE_EXPRESSION_H
