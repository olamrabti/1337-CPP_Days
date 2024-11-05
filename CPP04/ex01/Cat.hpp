#ifndef CAT_CLASS
#define CAT_CLASS

#include <iostream>
#include "Brain.hpp"

class Cat : public Animal
{
private:
    Brain *_brain;

public:
    Cat();
    Cat(const Cat &src);
    Cat &operator=(const Cat &rhs);
    ~Cat();
    void makeSound() const;
};
#endif