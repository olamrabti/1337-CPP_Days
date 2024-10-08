#include "Zombie.hpp"

Zombie::Zombie() {
};

Zombie::~Zombie()
{
    std::cout << this->name << " is Destroyed" << std::endl;
};

void Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::set_name(std::string new_name)
{
    this->name = new_name;
};
