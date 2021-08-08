# DifferentiationCPP

C++ library for basic function differentiation. Google C++ test [library](https://github.com/google/googletest) is used for testing. 

Here is an example of a test:
```c++
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
```