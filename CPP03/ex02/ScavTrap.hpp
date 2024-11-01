#ifndef SCAV_TRAP_CLASS
#define SCAV_TRAP_CLASS

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap &src);
    ScavTrap &operator=(const ScavTrap &rhs);
    ~ScavTrap();
    void attack(const std::string &target);
    void guardGate();
};
#endif