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
    const int size = 4;
    Animal *animals[size];

    for (int i = 0; i < size / 2; ++i)
    {
        animals[i] = new Dog();
    }
    for (int i = size / 2; i < size; ++i)
    {
        animals[i] = new Cat();
    }
    for (int i = 0; i < size; ++i)
    {
        delete animals[i];
    }

    return 0;
}
