
#include "HumanB.hpp"

HumanB::HumanB(std::string h_name) : name(h_name) {};

HumanB::~HumanB() {};

void HumanB::attack()
{
    std::cout << this->name << " attacks with their "
              << this->weapon.getType() << std::endl;
}
void HumanB::setWeapon(Weapon new_wpn)
{
    this->weapon = new_wpn;
};