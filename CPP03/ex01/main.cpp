#include "ScavTrap.hpp"

int main()
{
    ClapTrap player1("First_player");
    ScavTrap player2("Second_player");

    player1.attack(player2.get_name());
    player2.takeDamage(8);
    player2.beRepaired(8);

    player2.attack(player1.get_name());
    player1.takeDamage(5);
    player2.attack(player1.get_name());
    player1.takeDamage(5);

    player1.attack(player2.get_name());
    player2.guardGate();
    return 0;
}