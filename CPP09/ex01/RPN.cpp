#include "RPN.hpp"

RPN::RPN(void) {}

RPN::RPN(RPN const &src)
{
	*this = src;
}

RPN::~RPN(void) {}

RPN const &RPN::operator=(RPN const &rhs)
{
	if (this != &rhs)
		_numbers = rhs._numbers;
	return (*this);
}

void RPN::store_numbers(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
	{
		const std::string op = av[i];
		if (op == "+" || op == "-" || op == "*" || op == "/")
			do_the_math(op[0]);
		else
		{
			int num = std::atoi(op.c_str());
			_numbers.push(num);
			std::cout << "number.top : " << _numbers.top() << std::endl;
		}
	}
}

void RPN::do_the_math(char op)
{
	std::cout << "op :" << op << std::endl;
	if (_numbers.size() < 2)
	{
		std::cerr << "Error: Not enough numbers for operation " << op << std::endl;
		return;
	}

	int b = _numbers.top();
	_numbers.pop();
	int a = _numbers.top();
	_numbers.pop();

	switch (op)
	{
	case '+':
		_numbers.push(a + b);
		break;
	case '-':
		_numbers.push(a - b);
		break;
	case '*':
		_numbers.push(a * b);
		break;
	case '/':
		if (b != 0)
			_numbers.push(a / b);
		else
			std::cerr << "Error: Division by zero" << std::endl;
		break;
	default:
		std::cerr << "Error: Unknown operator " << op << std::endl;
	}
}

int RPN::get_result() const
{
	return _numbers.top();
}
