#ifndef RPN_HPP
#define RPN_HPP
#include <stack>
#include <iostream>

class RPN
{
public:
	std::stack<int> _numbers;
	RPN(void);
	RPN(RPN const &src);
	RPN const &operator=(RPN const &rhs);
	~RPN(void);
	void parse_numbers(const std::string &expression);
	void do_the_math(char op);
};

#endif