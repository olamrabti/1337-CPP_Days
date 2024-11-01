#ifndef DOG_CLASS
#define DOG_CLASS

#include <iostream>

class Dog : public Animal
{
public:
    Dog();
    Dog(const Dog &src);
    Dog &operator=(const Dog &rhs);
    ~Dog();
    void makeSound() const;
};
#endif