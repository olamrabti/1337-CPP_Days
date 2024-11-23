#include "Base.hpp"

int main()
{
    Base *randomInstance = generate();

    std::cout << "Identify using pointer: ";
    identify(randomInstance);

    std::cout << "Identify using reference: ";
    identify(*randomInstance);

    delete randomInstance;

    return 0;
}
