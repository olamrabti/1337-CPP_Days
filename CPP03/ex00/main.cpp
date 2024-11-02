#include "ClapTrap.hpp"

int main()
{
    ClapTrap player1("\033[1;31m First_Player\033[0m");
    ClapTrap player2("\033[1;34m Second_player\033[0m");

    player1.attack(player2.get_name());
    player2.takeDamage(12);
    player2.beRepaired(12);

    player2.attack(player1.get_name());
    player1.takeDamage(5);
    player2.attack(player1.get_name());
    player1.takeDamage(5);

    player1.attack(player2.get_name());
    return 0;
}