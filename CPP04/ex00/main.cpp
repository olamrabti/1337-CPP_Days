#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

void f()
{
    system("leaks animal");
}

int main()
{
    atexit(f);
    {
        std::cout << "\n           >> Test 1 <<\n"
                  << std::endl;
        const Animal *meta = new Animal();
        const Animal *j = new Dog();
        const Animal *i = new Cat();
        std::cout << " j -> type : " << j->getType() << " " << std::endl;
        std::cout << " i -> type : " << i->getType() << " " << std::endl;
        i->makeSound();
        j->makeSound();
        meta->makeSound();
        delete (meta);
        delete (i);
        delete (j);
    }
    {
        std::cout << "\n           >> Test 2 <<\n"
                  << std::endl;
        const WrongAnimal *meta = new WrongAnimal();
        const WrongAnimal *i = new WrongCat();
        const WrongCat *j = new WrongCat();
        std::cout << " meta (Used as WrongAnimal*) -> type : " << meta->getType() << " and says : " << std::endl;
        meta->makeSound();
        std::cout << " i (Used as WrongAnimal*) -> type : " << i->getType() << " and says : " << std::endl;
        i->makeSound();
        std::cout << " j (Used as WrongCat*) -> type : " << j->getType() << " and says : " << std::endl;
        j->makeSound();
        delete (meta);
        delete (i);
        delete (j);
    }
    return 0;
}
