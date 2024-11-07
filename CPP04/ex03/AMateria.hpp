#ifndef AMATERIA_CLASS_HPP
#define AMATERIA_CLASS_HPP

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
protected:
    std::string _type;

public:
    AMateria();
    AMateria(std::string const &type);
    AMateria(const AMateria &src);
    AMateria &operator=(const AMateria &rhs);
    virtual ~AMateria();
    std::string const &getType() const;
    virtual AMateria *clone() const = 0;
    virtual void use(ICharacter &target);
};

#endif
