#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    ClapTrap player1("chi wahd");
    ScavTrap player2("wahd akhor");
    FragTrap player3("wahd akhor");

    player1.attack(player2.get_name());
    player2.takeDamage(8);
    player2.beRepaired(10);
    player2.attack(player1.get_name());
    player1.takeDamage(5);
    player3.attack(player1.get_name());
    player2.guardGate();
    player1.takeDamage(5);
    player1.attack(player2.get_name());
    player3.highFivesGuy();
    return 0;
}