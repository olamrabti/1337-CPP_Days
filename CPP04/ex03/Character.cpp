#include "Character.hpp"

Character::Character()
{
    std::cout << "Default Constructor called for Character" << std::endl;
}

Character::Character(const std::string &name) : _name(name)
{
    std::cout << "Parametrized Constructor(name) called for Character" << std::endl;
}

Character::Character(const Character &src)
{
    std::cout << "Copy constructor called for Character" << std::endl;
    *this = src;
}

Character &Character::operator=(const Character &rhs)
{
    if (this != &rhs)
    {
        _name = rhs._name;
        for (int i = 0; i < 4; i++)
        {
            if (inventory[i])
                delete (inventory[i]);
            inventory[i] = NULL;
        }
        for (int i = 0; i < 4; i++)
        {
            if (rhs.inventory[i])
                inventory[i] = rhs.inventory[i]->clone();
            else
                inventory[i] = NULL;
        }
    }
    return *this;
}

Character::~Character()
{
    std::cout << "Destructor called for Character" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i])
            delete (inventory[i]);
        inventory[i] = NULL;
    }
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
