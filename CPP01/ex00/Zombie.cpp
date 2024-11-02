#include "Zombie.hpp"

Zombie::Zombie() {
};

Zombie::~Zombie()
{
    std::cout << name << " is Destroyed" << std::endl;
};

void Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::set_name(std::string new_name)
{
    name = new_name;
};
