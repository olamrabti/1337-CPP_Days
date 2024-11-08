#include "AMateria.hpp"

AMateria::AMateria() : _type(NULL)
{
    std::cout << "Default constructor called for AMateria" << std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type)
{
    std::cout << "Copy constructor called for AMateria" << std::endl;
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
    std::cout << "Destructor called for AMateria" << std::endl;
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
