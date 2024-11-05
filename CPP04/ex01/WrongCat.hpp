#ifndef WRONG_CAT_CLASS
#define WRONG_CAT_CLASS

#include <iostream>

class WrongCat : public WrongAnimal
{
public:
    WrongCat();
    WrongCat(const WrongCat &src);
    WrongCat &operator=(const WrongCat &rhs);
    ~WrongCat();
    void makeSound() const;
};
#endif