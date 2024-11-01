#ifndef ANIMAL_CLASS
#define ANIMAL_CLASS

#include <iostream>

class Animal
{
protected:
    std::string type;

public:
    Animal();
    Animal(const Animal &src);
    Animal &operator=(const Animal &rhs);
    ~Animal();
    virtual void makeSound() const;
    const std::string &getType() const;
};

#endif