#include "AAnimal.hpp"
#include "Cat.hpp"

Cat::Cat() : AAnimal()
{
    std::cout << "Default constructor called for Cat" << std::endl;
    type = "Cat";
    _brain = new Brain();
}

Cat::Cat(const Cat &src)
{
    std::cout << "Copy constructor called for Cat" << std::endl;
    *this = src;
}

Cat &Cat::operator=(const Cat &rhs)
{
    if (this != &rhs)
        type = rhs.type;
    return *this;
}

Cat::~Cat()
{
    delete (_brain);
    std::cout << "Destructor called for Cat" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow!" << std::endl;
}