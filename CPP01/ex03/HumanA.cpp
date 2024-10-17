#include "HumanA.hpp"

HumanA::HumanA(std::string h_name, Weapon &the_weapon) : name(h_name), weapon(the_weapon) {};

HumanA::~HumanA()
{
    std::cout << this->name << "Destroyed" << std::endl;
};

void HumanA::attack()
{
    std::cout << this->name << " attacks with their "
              << this->weapon.getType() << std::endl;
};