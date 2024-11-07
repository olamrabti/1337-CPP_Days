#ifndef MATERIA_SOURCE_CLASS_HPP
#define MATERIA_SOURCE_CLASS_HPP

#include <iostream>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
    AMateria *inventory[4];

public:
    MateriaSource();
    MateriaSource(const MateriaSource &src);
    MateriaSource &operator=(const MateriaSource &rhs);
    ~MateriaSource();
    void learnMateria(AMateria *m);
    AMateria *createMateria(std::string const &m);
};
#endif