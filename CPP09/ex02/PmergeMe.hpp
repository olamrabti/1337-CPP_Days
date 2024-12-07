#ifndef PMERGEME_HPP
# define PMERGEME_HPP

class PmergeMe
{
	public :
		PmergeMe(void);
		PmergeMe(PmergeMe const &copy);
		~PmergeMe(void);
		PmergeMe const &operator = (PmergeMe const &rhs);
};

#endif