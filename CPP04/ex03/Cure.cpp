#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
    std::cout << "Default constructor called for Cure" << std::endl;
}

Cure::Cure(const Cure &src)
{
    std::cout << "Copy constructor called for Cure" << std::endl;
    *this = src;
}

Cure &Cure::operator=(const Cure &rhs)
{
    if (this != &rhs)
        _type = rhs._type;
    return *this;
}

Cure::~Cure()
{
    std::cout << "Destructor called for Cure" << std::endl;
}

void Cure::setType(std::string type)
{
    _type = type;
}

AMateria *Cure::clone() const
{
    return new Cure();
}

void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "\'s wounds *" << std::endl;
}
