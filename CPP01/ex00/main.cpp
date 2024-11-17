#include "Zombie.hpp"

void f()
{
    system("leaks zombie");
}

int main()
{
    Zombie *z1;
    atexit(f);
    z1 = newZombie("First_zombie");
    z1->announce();
    randomChump("a random zombie");
    delete z1;
    return 0;
}