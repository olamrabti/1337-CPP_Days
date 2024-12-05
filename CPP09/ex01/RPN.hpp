#ifndef RPN_HPP
#define RPN_HPP
#include <stack>
#include <iostream>
class RPN
{
public:
	std::stack<int> _numbers;
	RPN(void);
	RPN(RPN const &copy);
	~RPN(void);
	RPN const &operator=(RPN const &rhs);

	void store_numbers(int argc, char **argv);
	void do_the_math(char op);
	int get_result() const;
};

#endif