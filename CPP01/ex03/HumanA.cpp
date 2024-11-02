#include "HumanA.hpp"

HumanA::HumanA(std::string h_name, Weapon &the_weapon) : name(h_name), weapon(the_weapon) {};

HumanA::~HumanA()
{
    std::cout << name << "Destroyed" << std::endl;
};

void HumanA::attack()
{
    std::cout << name << " attacks with their "
              << weapon.getType() << std::endl;
};