#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "Default Contructor called for ClapTrap" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_pts(10), _energy_pts(10), _attack_damage(0)
{
    std::cout << "Contructor called : " << _name << " is Ready..." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
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

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called : " << _name << " is Destoyed." << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (_energy_pts >= 0 && _hit_pts >= 0)
    {
        std::cout << "ClapTrap " << _name << " attacks " << target << std::endl;
        _energy_pts--;
    }
    else
        std::cout << "Oops! " << _name << " Cant Attack now ! He is probably dead! Or doesnt have enough hit points" << std::endl;
    return;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if ((_hit_pts - amount) < 0)
        return;
    _hit_pts -= amount;
    std::cout << _name << " loses " << amount << " of hit points" << std::endl;
    std::cout << _name << " has now " << _hit_pts << " of hit points" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    std::cout << _name << " is Reparing..." << std::endl;
    _hit_pts += amount;
    if (_energy_pts > 0)
        _energy_pts--;
    std::cout << _name << " has now " << _hit_pts << " of hit points" << std::endl;
}

const std::string &ClapTrap::get_name(void)
{
    return _name;
}
