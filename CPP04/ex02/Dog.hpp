#ifndef DOG_CLASS
#define DOG_CLASS

#include <iostream>
#include "Brain.hpp"

class Dog : public AAnimal
{
private:
    Brain *_brain;

public:
    Dog();
    Dog(const Dog &src);
    Dog &operator=(const Dog &rhs);
    ~Dog();
    void makeSound() const;
};
#endif