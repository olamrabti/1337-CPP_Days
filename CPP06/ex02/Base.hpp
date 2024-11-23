#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>

class Base
{
public:
	virtual ~Base();
};

Base *generate();
void identify(Base *p);
void identify(Base &p);

#endif