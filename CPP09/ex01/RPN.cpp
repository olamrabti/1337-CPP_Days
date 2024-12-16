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

void RPN::parse_numbers(const std::string &expr)
{
	int i = 0;
	std::string s;
	int start;
	int num;

	while (expr[i])
	{
		if (isspace(expr[i]))
		{
			i++;
			continue;
		}
		if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/')
			do_the_math(expr[i]);
		else if (isdigit(expr[i]))
		{
			start = i;
			while (isdigit(expr[i]))
				i++;
			if (i - start >= 2)
				throw std::runtime_error("Error: Numbers must be less than 10");
			s = expr.substr(start, i - start);
			num = std::atoi(s.c_str());
			_numbers.push(num);
		}
		else
			throw std::runtime_error("Error");
		i++;
	}
	if (!_numbers.empty())
		std::cout << _numbers.top() << std::endl;
}

void RPN::do_the_math(char op)
{
	if (_numbers.size() < 2)
	{
		std::cerr << "Error: ( " << op << " ) ";
		throw std::runtime_error("Not enough numbers for this operation ");
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
		if (b == 0)
			throw std::runtime_error("Error: Division by zero");
		_numbers.push(a / b);
		break;
	default:
		throw std::runtime_error("Error: Invalid operator");
	}
}
