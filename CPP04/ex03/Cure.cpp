#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(const Cure &src)
{
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
