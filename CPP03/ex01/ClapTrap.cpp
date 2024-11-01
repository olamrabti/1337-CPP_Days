#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "Default Contructor called for ClapTrap" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_pts(10), _energy_pts(10), _attack_damage(0)
{
    std::cout << "Contructor called : " << this->_name << " is Ready as a ClapTrap..." << std::endl;
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
        this->_name = rhs._name;
        this->_hit_pts = rhs._hit_pts;
        this->_energy_pts = rhs._energy_pts;
        this->_attack_damage = rhs._attack_damage;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called : ClapTrap " << this->_name << " is Destoyed." << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (this->_energy_pts == 0 || this->_hit_pts == 0)
    {
        std::cout << "\nOops! " << this->_name << " Cant Attack now ! He is probably dead!" << std::endl;
        return;
    }
    std::cout << "\nClapTrap " << this->_name << " attacks " << target << std::endl;
    this->_energy_pts--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    this->_hit_pts -= amount;
    std::cout << this->_name << " loses " << amount << " of hit points" << std::endl;
    std::cout << this->_name << " has now " << this->_hit_pts << " of hit points" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    std::cout << "\n"
              << this->_name << " is Reparing..." << std::endl;
    this->_hit_pts += amount;
    this->_energy_pts--;
    std::cout << this->_name << " has now " << this->_hit_pts << " of hit points" << std::endl;
}

const std::string &ClapTrap::get_name(void)
{
    return this->_name;
}
