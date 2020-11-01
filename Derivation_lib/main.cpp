#include <iostream>

#include "Expression.h"
#include "Addition.h"
#include "Multiplication.h"
#include "Number.h"
#include "Variable.h"

int main(int argc, char **argv) {
    Expression * e = new Addition(
            new Multiplication(
                    new Number(2), new Variable("x")
            ),
            new Number(3)
    );

    std::cout << "e = " << *e << std::endl;
    std::cout << "de/dx = " << *(e->derive("x")) << std::endl;
}
