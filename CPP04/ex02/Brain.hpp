#ifndef BRAIN_CLASS
#define BRAIN_CLASS

#include <iostream>

class Brain
{
public:
    Brain();
    Brain(const Brain &src);
    Brain &operator=(const Brain &rhs);
    virtual ~Brain();
    std::string ideas[100];
};

#endif