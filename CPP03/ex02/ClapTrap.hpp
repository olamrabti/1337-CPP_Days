#ifndef CLAP_TRAP_CLASS
#define CLAP_TRAP_CLASS

#include <iostream>

class ClapTrap
{
protected:
    std::string _name;
    int _hit_pts;
    int _energy_pts;
    int _attack_damage;

public:
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap &src);
    ClapTrap &operator=(const ClapTrap &rhs);
    ~ClapTrap();
    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    const std::string &get_name(void);
};

#endif