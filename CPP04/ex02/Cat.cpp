#include "AAnimal.hpp"
#include "Cat.hpp"

Cat::Cat() : AAnimal(), _brain(new Brain())
{
    std::cout << "Default constructor called for Cat" << std::endl;
    type = "Cat";
}

Cat::Cat(const Cat &src) : AAnimal(src), _brain(new Brain(*src._brain))
{
    std::cout << "Copy constructor called for Cat" << std::endl;
    *this = src;
}

Cat &Cat::operator=(const Cat &rhs)
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

Cat::~Cat()
{
    delete (_brain);
    std::cout << "Destructor called for Cat" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "🔊 : Meow!" << std::endl;
}
