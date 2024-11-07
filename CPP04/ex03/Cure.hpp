#ifndef CURE_CLASS_HPP
#define CURE_CLASS_HPP

#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria
{

public:
    Cure();
    Cure(const Cure &src);
    Cure &operator=(const Cure &rhs);
    ~Cure();
    void setType(std::string type);
    AMateria *clone() const;
    void use(ICharacter &target);
};

#endif
