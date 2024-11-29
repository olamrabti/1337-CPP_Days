#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

class MutantStack
{
	public :
		MutantStack(void);
		MutantStack(MutantStack const &copy);
		~MutantStack(void);
		MutantStack const &operator = (MutantStack const &rhs);
};

#endif