#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Default constructor called for Brain" << std::endl;
}

Brain::Brain(const Brain &src)
{
    std::cout << "Copy constructor called for Brain" << std::endl;
    *this = src;
}

Brain &Brain::operator=(const Brain &rhs)
{
    if (this != &rhs)
    {
        for (int i = 0; i < 100; ++i)
            ideas[i] = rhs.ideas[i];
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Destructor called for Brain" << std::endl;
}
