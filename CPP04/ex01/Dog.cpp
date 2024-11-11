#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog() : Animal(), _brain(new Brain())
{
    std::cout << "Default constructor called for Dog" << std::endl;
    type = "Dog";
}

Dog::Dog(const Dog &src) : Animal(src), _brain(new Brain(*src._brain))
{
    std::cout << "Copy constructor called for Dog" << std::endl;
    *this = src;
}

Dog &Dog::operator=(const Dog &rhs)
{
    std::cout << "Copy Assignment operator called for Dog" << std::endl;
    if (this != &rhs)
    {
        type = rhs.type;
        delete (_brain);
        _brain = new Brain(*rhs._brain);
    }
    return *this;
}

Dog::~Dog()
{
    delete (_brain);
    std::cout << "Destructor called for Dog" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "🔊 : Wuff!" << std::endl;
}
