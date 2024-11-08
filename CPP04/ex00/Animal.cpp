#include "Animal.hpp"

Animal::Animal() : type("")
{
    std::cout << "Default constructor called for Animal" << std::endl;
}

Animal::Animal(const Animal &src)
{
    std::cout << "Copy constructor called for Animal" << std::endl;
    *this = src;
}

Animal &Animal::operator=(const Animal &rhs)
{
    if (this != &rhs)
        type = rhs.type;
    return *this;
}

Animal::~Animal()
{
    std::cout << "Destructor called for Animal" << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "🔇 : Make a sound ?! I need to know how am I first 😏 " << std::endl;
}

const std::string &Animal::getType() const
{
    return type;
}
