#include "Base.hpp"

int main()
{
    Base *test = generate();

    std::cout << "Identify using pointer: ";
    identify(test);

    std::cout << "Identify using reference: ";
    identify(*test);

    delete test;

    return 0;
}
