#include "Span.hpp"

Span::Span() {}
Span::~Span() {}
Span::Span(unsigned int N) : _max(N) {}

Span::Span(const Span &src) : _max(src._max), c(src.c) {}

Span &Span::operator=(const Span &rhs)
{
	if (this != &rhs)
	{
		_max = rhs._max;
		c = rhs.c;
	}
	return *this;
}

void Span::addNumber(int number)
{
	if (c.size() >= _max)
		throw std::overflow_error("Span is full.");
	c.push_back(number);
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	size_t range_size = std::distance(begin, end);
	if (c.size() + range_size > _max)
		throw std::overflow_error("Span doesnt have enough capacity for this range.");
	c.insert(c.end(), begin, end);
}

unsigned int Span::shortestSpan() const
{
	if (c.size() < 2)
		throw std::logic_error("no span can be found");
	std::vector<int> sorted = c;
	std::sort(sorted.begin(), sorted.end());
	unsigned int minSpan = INT_MAX;
	for (size_t i = 0; i < sorted.size() - 1; i++)
	{
		unsigned int span = sorted[i + 1] - sorted[i];
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}

unsigned int Span::longestSpan() const
{
	if (c.size() < 2)
		throw std::logic_error("Not enough numbers to find a span.");
	std::vector<int> sortedNumbers = c;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());
	return sortedNumbers.back() - sortedNumbers.front();
}

void Span::print_all() const
{
	for (size_t i = 0; i < c.size(); i++)
	{
		std::cout << c[i] << " ";
	}
	std::cout << std::endl;
}

std::vector<int>::iterator Span::begin()
{
	return c.begin();
}
std::vector<int>::iterator Span::end()
{
	return c.end();
}