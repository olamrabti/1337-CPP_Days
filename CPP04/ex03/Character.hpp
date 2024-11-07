#ifndef CHARACTER_CLASS_HPP
#define CHARACTER_CLASS_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
    std::string _name;
    AMateria *inventory[4];

public:
    Character();
    Character(const std::string &name);
    Character(const Character &src);
    Character &operator=(const Character &rhs);
    ~Character();
    std::string const &getName() const;
    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter &target);
};

#endif