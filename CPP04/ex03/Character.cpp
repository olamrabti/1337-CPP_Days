#include "Character.hpp"

Character::Character()
{
}

Character::Character(const std::string &name) : _name(name)
{
}

Character::Character(const Character &src)
{
    *this = src;
}

Character &Character::operator=(const Character &rhs)
{
    if (this != &rhs)
    {
        _name = rhs._name;
        for (int i = 0; i < 4; i++)
        {
            inventory[i] = rhs.inventory[i];
        }
    }
    return *this;
}

Character::~Character()
{
}

std::string const &Character::getName() const
{
    return _name;
}

void Character::equip(AMateria *m)
{
    for (int i = 0; i < 4; i++)
    {
        if (!inventory[i])
        {
            inventory[i] = m;
            break;
        }
    }
}

void Character::unequip(int idx)
{
    if (inventory[idx] || inventory[idx]->getType() == "")
        return;
}

void Character::use(int idx, ICharacter &target)
{
    if (!inventory[idx])
        return;
    inventory[idx]->use(target);
}
