#include "Weapon.hpp"

Weapon::Weapon(std::string new_type) : type(new_type) {
                                       };
Weapon::~Weapon() {
};

void Weapon::setType(std::string new_type)
{
    this->type = new_type;
};

const std::string &Weapon::getType() const
{
    return this->type;
};
