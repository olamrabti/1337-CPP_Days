#include "AMateria.hpp"

AMateria::AMateria() : _type(NULL)
{
}

AMateria::AMateria(std::string const &type) : _type(type)
{
}

AMateria::AMateria(const AMateria &src)
{
    *this = src;
}

AMateria &AMateria::operator=(const AMateria &rhs)
{
    if (this != &rhs)
        _type = rhs._type;
    return *this;
}

AMateria::~AMateria()
{
}

std::string const &AMateria::getType() const
{
    return _type;
}

void AMateria::use(ICharacter &target)
{
    if (target.getName() == "")
        return;
}
