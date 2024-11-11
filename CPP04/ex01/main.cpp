#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

void f()
{
    system("leaks brain");
}

int main()
{
    atexit(f);
    int size = 4;
    Animal *animals[size];

    for (int i = 0; i < size / 2; ++i)
    {
        std::cout << "     INITIALIZING Animal[" << i << "]" << std::endl;
        animals[i] = new Dog();
    }
    for (int i = size / 2; i < size; ++i)
    {
        std::cout << "     INITIALIZING Animal[" << i << "]" << std::endl;
        animals[i] = new Cat();
    }
    std::cout << "\n-------------------------My tests--------------------------\n"
              << std::endl;
    std::cout << "     For this Test We Have : ( " << size << " ) Animals.\n"
              << std::endl;
    for (int i = 0; i < size; ++i)
    {
        std::cout << "Animal number : " << i + 1 << " is a " << animals[i]->getType() << " and says : " << std::endl;
        animals[i]->makeSound();
    }
    std::cout << "-----------------------------------------------------------" << std::endl;
    for (int i = 0; i < size; ++i)
    {
        std::cout << "     DELETING Animal[" << i << "]" << std::endl;
        delete animals[i];
    }
    std::cout << "\n------------------ Eval sheet Test ----------------------\n"
              << std::endl;
    {
        Dog basic;
        {
            Dog tmp = basic;
        }
    }

    return 0;
}
