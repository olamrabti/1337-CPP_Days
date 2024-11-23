#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdint>
#include <iostream>

struct Data
{
	char c;
	int i;
	float f;
};

class Serializer
{
private:
	Serializer(void);
	Serializer(Serializer const &copy);
	Serializer const &operator=(Serializer const &rhs);

public:
	~Serializer(void);
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
};

#endif