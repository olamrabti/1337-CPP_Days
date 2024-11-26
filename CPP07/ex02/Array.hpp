#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>

class Array
{
private:
	T *elements;
	size_t len;

public:
	Array(void);
	Array(unsigned int n);
	Array(Array const &src);
	~Array(void);
	Array<T> &operator=(const Array<T> &rhs);
	T &operator[](unsigned int index);
	const T &operator[](unsigned int index) const;
	size_t size(void) const;
};

template <typename T>
Array<T>::Array() : elements(NULL), len(0){};

template <typename T>
Array<T>::~Array(void)
{
	delete[] elements;
}

template <typename T>
Array<T>::Array(unsigned int n) : elements(NULL), len(n)
{
	try
	{
		elements = new T[n]();
	}
	catch (const std::bad_alloc &e)
	{
		std::cerr << "Memory allocation failed: " << e.what() << std::endl;
		throw;
	}
};

template <typename T>
Array<T>::Array(const Array<T> &src) : len(src.len)
{
	try
	{
		elements = new T[src.len];
		for (size_t i = 0; i < len; ++i)
		{
			elements[i] = src.elements[i];
		}
	}
	catch (const std::bad_alloc &e)
	{
		std::cerr << "Memory allocation failed: " << e.what() << std::endl;
		throw;
	}
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &rhs)
{
	if (this != &rhs)
	{
		delete[] elements;
		len = rhs.len;
		try
		{
			elements = new T[len];
			for (size_t i = 0; i < len; ++i)
			{
				elements[i] = rhs.elements[i];
			}
		}
		catch (const std::bad_alloc &e)
		{
			std::cerr << "Memory allocation failed: " << e.what() << std::endl;
			throw;
		}
	}
	return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= len)
		throw std::out_of_range("Index is out of bounds.");
	return elements[index];
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
	if (index >= len)
		throw std::out_of_range("Index is out of bounds.");
	return elements[index];
}

template <typename T>
size_t Array<T>::size(void) const
{
	return len;
}

#endif