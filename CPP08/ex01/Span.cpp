#include "Span.hpp"

Span::Span() {}
Span::Span(unsigned int N) : _max(N) {}

Span::~Span() {}

void Span::addNumber(int number)
{
	if (_numbers.size() >= _max)
		throw std::overflow_error("Span is full.");
	_numbers.push_back(number);
}

template <typename Iterator>
void Span::addNumbers(Iterator begin, Iterator end)
{
	size_t rangeSize = std::distance(begin, end);
	if (_numbers.size() + rangeSize > _max)
		throw std::overflow_error("Span doesnt have enough capacity for this range.");
	_numbers.insert(_numbers.end(), begin, end);
}

unsigned int Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw std::logic_error("no span can be found");
	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());
	unsigned int minSpan = std::numeric_limits<unsigned int>::max();
	for (size_t i = 0; i < sorted.size() - 1; ++i)
	{
		unsigned int span = sorted[i + 1] - sorted[i];
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}

unsigned int Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw std::logic_error("Not enough numbers to find a span.");
	std::vector<int> sortedNumbers = _numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());
	return sortedNumbers.back() - sortedNumbers.front();
}
