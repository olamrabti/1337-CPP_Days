#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    std::cout << "Default constructor called for MateriaSource" << std::endl;
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
    return;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
    std::cout << "Copy constructor called for MateriaSource" << std::endl;
    *this = copy;
    return;
}

MateriaSource::~MateriaSource()
{
    std::cout << "Destructor called for MateriaSource" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i])
            delete inventory[i];
    }
    return;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &copy)
{
    if (this != &copy)
    {
        for (int i = 0; i < 4; i++)
        {
            if (inventory[i])
            {
                delete inventory[i];
                inventory[i] = NULL;
            }
        }
        for (int i = 0; i < 4; i++)
        {
            if (copy.inventory[i])
                inventory[i] = copy.inventory[i]->clone();
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria *m)
{
    for (int i = 0; i < 4; i++)
    {
        if (!inventory[i])
        {
            inventory[i] = m;
            break;
        }
    }
    return;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i] && inventory[i]->getType() == type)
            return inventory[i]->clone();
    }
    return 0;
}
