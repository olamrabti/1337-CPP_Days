#include "AAnimal.hpp"

AAnimal::AAnimal()
{
    std::cout << "Default constructor called for AAnimal" << std::endl;
}

AAnimal::AAnimal(const AAnimal &src)
{
    std::cout << "Copy constructor called for AAnimal" << std::endl;
    *this = src;
}

AAnimal &AAnimal::operator=(const AAnimal &rhs)
{
    if (this != &rhs)
        type = rhs.type;
    return *this;
}

AAnimal::~AAnimal()
{
    std::cout << "Destructor called for AAnimal" << std::endl;
}

void AAnimal::makeSound() const
{
    std::cout << "Make a sound ? Wait! Who am I ?" << std::endl;
}

const std::string &AAnimal::getType() const
{
    return type;
}
