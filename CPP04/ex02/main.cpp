#include "AAnimal.hpp"
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
    // atexit(f);

    const AAnimal *j = new Dog();
    const AAnimal *i = new Cat();
    std::cout << " The cat says : " << std::endl;
    i->makeSound();
    std::cout << " The dog says : " << std::endl;
    j->makeSound();

    delete (i);
    delete (j);

    return 0;
}