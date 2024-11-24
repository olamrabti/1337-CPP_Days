#ifndef ARRAY_HPP
#define ARRAY_HPP

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
	elements = new T[n](); // TODO learn more about this syntax
};

template <typename T>
Array<T>::Array(const Array<T> &copy) : len(copy.len)
{
	elements = new T[copy.len];
	for (size_t i = 0; i < len; ++i)
	{
		elements[i] = copy.elements[i];
	}
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &rhs)
{
	if (this != &rhs)
	{
		delete[] elements;
		len = rhs.len;
		elements = new T[len];
		for (size_t i = 0; i < len; ++i)
		{
			elements[i] = rhs.elements[i];
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
size_t Array<T>::size(void) const
{
	return len;
}

#endif