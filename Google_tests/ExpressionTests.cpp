//
// Created by Louis Delille on 31/10/2020.
//

//
// Created by Louis Delille on 30/10/2020.
//

#include <sstream>
#include <Variable.h>
#include <Number.h>
#include <Multiplication.h>
#include <Addition.h>

#include "gtest/gtest.h"


TEST(derivation_test, test_display_number) {
    Number n(2);
    std::ostringstream os;
    os << n;
    EXPECT_EQ(os.str(), "2");
}

TEST(derivation_test, test_display_variable) {
    const Expression *e = new Variable("x");
    std::ostringstream os;
    os << *e;
    EXPECT_EQ(os.str(), "x");
    delete e;
}

TEST(derivation_test, derivation_testNumber) {
    const Expression *e = new Number(-2);
    const Expression *f = e->derive("x");
    ASSERT_TRUE(nullptr != f);
    std::ostringstream os;
    os << *f;
    EXPECT_EQ(os.str(), "0");
    delete e;
    delete f;
}

TEST(derivation_test, derivation_test_variable) {
    const Expression *e = new Variable("x");
    const Expression *f = e->derive("x");
    ASSERT_TRUE(nullptr != f);
    std::ostringstream os1;
    os1 << *f;
    EXPECT_EQ(os1.str(), "1");
    delete f;

    f = e->derive("y");
    ASSERT_TRUE(nullptr != f);
    std::ostringstream os2;
    os2 << *f;
    EXPECT_EQ(os2.str(), "0");
    delete e;
    delete f;
}

TEST(derivation_test, display_test_variable) {
    const Expression *e = new Addition(new Variable("x"), new Number(-2));
    std::ostringstream os;
    os << *e;
    EXPECT_EQ(os.str(), "(x + -2)");
    delete e;
}

TEST(derivation_test, derivation_test_addition) {
    const Expression *e = new Addition(new Variable("x"), new Number(-10));
    const Expression *f = e->derive("x");
    ASSERT_TRUE(nullptr != f);
    std::ostringstream os;
    os << *f;
    EXPECT_EQ(os.str(), "(1 + 0)");
    delete e;
    delete f;
}

TEST(derivation_test, display_test_multiplication) {
    const Expression *e = new Multiplication(new Variable("y"), new Variable("z"));
    std::ostringstream os;
    os << *e;
    EXPECT_EQ(os.str(), "(y * z)");
    delete e;
}

TEST(derivation_test, derivation_test_multiplication) {
// This test expects (f * g)' = f' * g + f * g'
    const Expression *e = new Multiplication(
            new Variable("x"),
            new Multiplication(new Variable("y"), new Variable("z"))
    );
    const Expression *f = e->derive("x");
    ASSERT_TRUE(nullptr != f);
    std::ostringstream os;
    os << *f;
    EXPECT_EQ(os.str(), "((1 * (y * z)) + (x * ((0 * z) + (y * 0))))");
    delete e;
    delete f;
}

TEST(derivation_test, derivation_test_simplification_number_addition){
    // assert 1+0 = 1
    const Expression *e = new Addition(new Number(1), new Number(0));
    const Expression *f =e->simplify();
    ASSERT_TRUE(nullptr != f);
    std::ostringstream os;
    os << *f;
    ASSERT_EQ(os.str(), "1");
    delete f;
    delete e;
}

TEST(derivation_test, derivation_test_simplification_number_mulitplication){
    // assert 4*1 = 4
    const Expression *e = new Multiplication(new Number(1), new Number(4));
    const Expression *f =e->simplify();
    ASSERT_TRUE(nullptr != f);
    std::ostringstream os;
    os << *f;
    ASSERT_EQ(os.str(), "4");
    delete f;
    delete e;

}