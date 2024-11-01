#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout << "Default Contructor called for FragTrap" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    _hit_pts = 100;
    _energy_pts = 100;
    _attack_damage = 30;
    std::cout << "Contructor called : " << _name << " is Ready as a FragTrap..." << std::endl;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src._name)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs)
{
    if (this != &rhs)
    {
        _name = rhs._name;
        _hit_pts = rhs._hit_pts;
        _energy_pts = rhs._energy_pts;
        _attack_damage = rhs._attack_damage;
    }
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "Destructor called : FragTrap " << _name << " is Destoyed." << std::endl;
}

void FragTrap::attack(const std::string &target)
{
    if (_energy_pts == 0 || _hit_pts == 0)
    {
        std::cout << "\nOops! " << _name << " Cant Attack now ! He is probably dead!" << std::endl;
        return;
    }
    std::cout << "\nFragTrap " << _name << " attacks " << target << std::endl;
    _energy_pts--;
}

void FragTrap::highFivesGuy()
{
    std::cout << "FragTrap " << _name << " REQUESTS A HIGHFIVE OR WHATEVER" << std::endl;
}
