#include "Weapon.hpp"

void Weapon::setType(std::string new_type)
{
    this->type = new_type;
};

const std::string &Weapon::getType() const
{
    return this->type;
}
