#ifndef CAT_CLASS
#define CAT_CLASS

#include <iostream>

class Cat : public Animal
{
public:
    Cat();
    Cat(const Cat &src);
    Cat &operator=(const Cat &rhs);
    ~Cat();
    void makeSound() const;
};
#endif