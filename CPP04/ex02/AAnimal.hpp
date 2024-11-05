#ifndef AANIMAL_CLASS
#define AANIMAL_CLASS

#include <iostream>

class AAnimal
{
protected:
    std::string type;

public:
    AAnimal();
    AAnimal(const AAnimal &src);
    AAnimal &operator=(const AAnimal &rhs);
    virtual ~AAnimal();
    virtual void makeSound() const = 0;
    const std::string &getType() const;
};

#endif