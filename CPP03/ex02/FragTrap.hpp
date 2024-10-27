#ifndef FRAG_TRAP_CLASS
#define FRAG_TRAP_CLASS

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
    FragTrap(std::string name);
    FragTrap(const FragTrap &src);
    FragTrap &operator=(const FragTrap &rhs);
    ~FragTrap();
    void attack(const std::string &target);
    void highFivesGuy();
};
#endif