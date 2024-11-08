#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
    std::cout << "Default constructor called for WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
    std::cout << "Copy constructor called for WrongAnimal" << std::endl;
    *this = src;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs)
{
    if (this != &rhs)
        type = rhs.type;
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "Destructor called for WrongAnimal" << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << " 🔊 : Wrong Animal Sound!" << std::endl;
}

const std::string &WrongAnimal::getType() const
{
    return type;
}
