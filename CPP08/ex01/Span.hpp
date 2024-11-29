#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>

class Span
{
private:
	unsigned int _max;
	std::vector<int> _numbers;
	Span();

public:
	Span(unsigned int N);
	~Span();
	void addNumber(int number);
	template <typename Iterator>
	void addNumbers(Iterator begin, Iterator end);
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;
};

#endif
