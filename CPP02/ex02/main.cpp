#include "Fixed.hpp"

void testComparisons()
{
    Fixed a(5);
    Fixed b(10);

    std::cout << "\nTesting Comparison Operators For : a =  " << a << " and b = " << b << std::endl;
    std::cout << "\na > b : " << (a > b ? "true" : "false") << std::endl;
    std::cout << "a < b : " << (a < b ? "true" : "false") << std::endl;
    std::cout << "a >= b : " << (a >= b ? "true" : "false") << std::endl;
    std::cout << "a <= b : " << (a <= b ? "true" : "false") << std::endl;
    std::cout << "a == b : " << (a == b ? "true" : "false") << std::endl;
    std::cout << "a != b : " << (a != b ? "true" : "false") << std::endl;
    std::cout << std::endl;
}

void testArithmetic()
{
    Fixed a(5.5f);
    Fixed b(2);

    std::cout << "\nTesting Arithmetic Operators For : a =  " << a << " and b = " << b << std::endl;
    std::cout << "\na + b: " << (a + b) << std::endl;
    std::cout << "a - b: " << (a - b) << std::endl;
    std::cout << "a * b: " << (a * b) << std::endl;
    std::cout << "a / b: " << (a / b) << std::endl;
    std::cout << std::endl;
}

int main(void)
{
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    testComparisons();
    testArithmetic();
    std::cout << "\nSubject's Tests : " << std::endl;
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;
    return 0;
}
