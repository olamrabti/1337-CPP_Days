#include "Serializer.hpp"

Serializer::Serializer(void) {}

Serializer::Serializer(Serializer const &copy)
{
	*this = copy;
}

Serializer::~Serializer(void) {}

Serializer const &Serializer::operator=(Serializer const &rhs)
{
	(void)rhs;
	return (*this);
}

uintptr_t Serializer::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}