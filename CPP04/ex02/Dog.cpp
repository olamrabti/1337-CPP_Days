#include "AAnimal.hpp"
#include "Dog.hpp"

Dog::Dog() : AAnimal()
{
    std::cout << "Default constructor called for Dog" << std::endl;
    type = "Dog";
    _brain = new Brain();
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
    delete (_brain);
    std::cout << "Destructor called for Dog" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Wuff" << std::endl;
}
