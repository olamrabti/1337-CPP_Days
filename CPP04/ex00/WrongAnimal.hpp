#ifndef WRONG_ANIMAL_CLASS
#define WRONG_ANIMAL_CLASS

#include <iostream>

class WrongAnimal
{
protected:
    std::string type;

public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal &src);
    WrongAnimal &operator=(const WrongAnimal &rhs);
    virtual ~WrongAnimal();
    virtual void makeSound() const;
    const std::string &getType() const;
};

#endif