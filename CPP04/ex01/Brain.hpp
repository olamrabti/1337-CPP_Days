#ifndef BRAIN_CLASS
#define BRAIN_CLASS

#include <iostream>

class Brain
{
private:
    std::string ideas[100];

public:
    Brain();
    Brain(const Brain &src);
    Brain &operator=(const Brain &rhs);
    virtual ~Brain();
};

#endif