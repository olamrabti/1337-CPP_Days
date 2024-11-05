#ifndef AMATERIA_CLASS_HPP
#define AMATERIA_CLASS_HPP

#include <iostream>

class AMateria
{
protected:
public:
    AMateria(std::string const &type);
    std::string const &getType() const; // Returns the materia type
    virtual AMateria *clone() const = 0;
    virtual void use(ICharacter &target);
};

#endif
