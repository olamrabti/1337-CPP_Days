#include "Zombie.hpp"

void randomChump(std::string name)
{
    Zombie *new_z;

    new_z = new Zombie;
    new_z->set_name(name);
    new_z->announce();
    delete new_z;
};