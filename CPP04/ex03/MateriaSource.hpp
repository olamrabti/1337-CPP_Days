#ifndef MATERIA_SOURCE_CLASS_HPP
#define MATERIA_SOURCE_CLASS_HPP

#include <iostream>

class IMateriaSource
{
public:
    virtual ~IMateriaSource();
    virtual void learnMateria(AMateria *) = 0;
    virtual AMateria *createMateria(std::string const &type) = 0;
};
#endif