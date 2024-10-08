
#include "HumanB.hpp"

HumanA::HumanB(std::string h_name, , Weapon const &the_weapon) : name(h_name), weapon(the_weapon){};

HumanA::~HumanB(){};

void HumanB::attack()
{
    std::cout << this->name << "attacks with their"
              << this->weapon.getType() << std::endl;
}