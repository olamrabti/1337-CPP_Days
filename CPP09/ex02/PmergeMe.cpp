#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(PmergeMe const &copy)
{
	*this = copy;
}

PmergeMe::~PmergeMe(void) {}

PmergeMe const	&PmergeMe::operator = (PmergeMe const &rhs)
{
	return (*this);
}