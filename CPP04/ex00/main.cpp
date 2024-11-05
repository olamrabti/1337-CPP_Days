#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

// void f()
// {
//     system("leaks animal");
// }

int main()
{
    // atexit(f);
    {
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
        const WrongAnimal *meta = new WrongAnimal();
        const WrongAnimal *i = new WrongCat();
        std::cout << " i -> type : " << i->getType() << " " << std::endl;
        i->makeSound();
        meta->makeSound();
        delete (meta);
        delete (i);
    }
    return 0;
}
