#include "Zombie.hpp"

// TODO delete me ......

void f()
{
    system("leaks horde");
}

int main()
{
    int n = 5;
    atexit(f); // TODO delete me ......

    Zombie *zombies = zombieHorde(n, "Zombie_name");
    for (int i = 0; i < n; ++i)
        zombies[i].announce();
    delete[] zombies;
    return 0;
}