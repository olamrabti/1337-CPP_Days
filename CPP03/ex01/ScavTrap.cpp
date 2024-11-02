#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "Default Contructor called for ScavTrap" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    _hit_pts = 100;
    _energy_pts = 50;
    _attack_damage = 20;
    std::cout << "Constructor called : " << _name << " is Ready as a ScavTrap..." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src._name)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
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

ScavTrap::~ScavTrap()
{
    std::cout << "Destructor called : ScavTrap " << _name << " is Destoyed." << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (_energy_pts <= 0)
    {
        std::cout << _name << " Doesnt have enough energy points!" << std::endl;
        return;
    }
    if (_hit_pts > 0)
    {
        std::cout << "\nScavTrap " << _name << " attacks " << target << std::endl;
        _energy_pts--;
    }
    else
        std::cout << "\nOops! " << _name << " Cant Attack now ! He is probably dead!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode" << std::endl;
}
