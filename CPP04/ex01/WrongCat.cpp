#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    std::cout << "Default constructor called for WrongCat" << std::endl;
    type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &src)
{
    std::cout << "Copy constructor called for WrongCat" << std::endl;
    *this = src;
}

WrongCat &WrongCat::operator=(const WrongCat &rhs)
{
    if (this != &rhs)
        type = rhs.type;
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "Destructor called for WrongCat" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << " 🔊 : Wrong Cat sound" << std::endl;
}
