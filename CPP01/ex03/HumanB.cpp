
#include "HumanB.hpp"

HumanB::HumanB(std::string h_name) : name(h_name), weapon(NULL) {};

HumanB::~HumanB()
{
    std::cout << this->name << "Destroyed" << std::endl;
};

void HumanB::attack()
{
    if (this->weapon == NULL)
    {
        std::cout << "Weapon not assigned!" << std::endl;
        return;
    }
    std::cout << this->name << " attacks with their "
              << this->weapon->getType() << std::endl;
}
void HumanB::setWeapon(Weapon &new_wpn)
{
    this->weapon = &new_wpn;
};