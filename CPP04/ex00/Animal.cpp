#include "Animal.hpp"

Animal::Animal()
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
    std::cout << "Make a sound ? Wait! Who am I ?" << std::endl;
}

const std::string &Animal::getType() const
{
    return type;
}
