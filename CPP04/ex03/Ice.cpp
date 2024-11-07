#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
}

Ice::Ice(const Ice &src)
{
    *this = src;
}

Ice &Ice::operator=(const Ice &rhs)
{
    if (this != &rhs)
        _type = rhs._type;
    return *this;
}

Ice::~Ice()
{
}

void Ice::setType(std::string type)
{
    _type = type;
}

AMateria *Ice::clone() const
{
    return new Ice();
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
