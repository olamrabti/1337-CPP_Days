#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>

class Span
{
private:
	unsigned int _max;
	std::vector<int> c;
	Span();

public:
	Span(unsigned int N);
	Span(const Span &src);
	Span &operator=(const Span &rhs);
	~Span();

	void addNumber(int number);
	void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;
	std::vector<int>::iterator begin();
	std::vector<int>::iterator end();
	void print_all() const;
};

#endif
