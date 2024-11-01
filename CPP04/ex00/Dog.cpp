#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog() : Animal()
{
    std::cout << "Default constructor called for Dog" << std::endl;
    type = "Dog";
}

Dog::Dog(const Dog &src)
{
    std::cout << "Copy constructor called for Dog" << std::endl;
    *this = src;
}

Dog &Dog::operator=(const Dog &rhs)
{
    if (this != &rhs)
        type = rhs.type;
    return *this;
}

Dog::~Dog()
{
    std::cout << "Destructor called for Dog" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Barks" << std::endl;
}
