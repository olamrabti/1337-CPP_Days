#ifndef ICE_CLASS_HPP
#define ICE_CLASS_HPP

#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria
{

public:
    Ice();
    Ice(const Ice &src);
    Ice &operator=(const Ice &rhs);
    ~Ice();
    void setType(std::string type);
    AMateria *clone() const;
    void use(ICharacter &target);
};

#endif
