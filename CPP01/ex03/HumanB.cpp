
#include "HumanB.hpp"

HumanB::HumanB(std::string h_name) : name(h_name), weapon(NULL) {};

HumanB::~HumanB()
{
    std::cout << name << "Destroyed" << std::endl;
};

void HumanB::attack()
{
    if (weapon == NULL)
    {
        std::cout << "Weapon not assigned!" << std::endl;
        return;
    }
    std::cout << name << " attacks with their "
              << weapon->getType() << std::endl;
}
void HumanB::setWeapon(Weapon &new_wpn)
{
    weapon = &new_wpn;
};