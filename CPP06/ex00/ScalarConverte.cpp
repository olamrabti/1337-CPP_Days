#include "ScalarConverte.hpp"
#include <iostream>
#include <cstdlib>
#include <cmath>

ScalarConverte::ScalarConverte(void) {}

ScalarConverte::ScalarConverte(ScalarConverte const &copy)
{
	*this = copy;
}

ScalarConverte::~ScalarConverte(void) {}

ScalarConverte const &ScalarConverte::operator=(ScalarConverte const &rhs)
{
	(void)rhs;
	return (*this);
}

static void toChar(double num)
{
	if (std::isnan(num) || std::isinf(num) || num < 0 || num > 127)
		std::cout << "char: impossible" << std::endl;
	else if (num < 32 || num == 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
}

static void toInt(double num)
{
	if (std::isnan(num) || std::isinf(num) || num < INT_MIN || num > INT_MAX)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(num) << std::endl;
}

static void toFloat(double num)
{
	if (std::isnan(num))
		std::cout << "float: nanf" << std::endl;
	else if (std::isinf(num))
		std::cout << "float: " << (num > 0 ? "+inff" : "-inff") << std::endl;
	else
	{
		std::cout << "float: " << static_cast<float>(num);
		if (num == static_cast<int>(num))
			std::cout << ".0";
		std::cout << "f" << std::endl;
	}
}

static void toDouble(double num)
{
	if (std::isnan(num))
		std::cout << "double: nan" << std::endl;
	else if (std::isinf(num))
		std::cout << "double: " << (num > 0 ? "+inf" : "-inf") << std::endl;
	else
	{
		std::cout << "double: " << num;
		if (num == static_cast<int>(num))
			std::cout << ".0";
		std::cout << std::endl;
	}
}

void ScalarConverte::convert(std::string input)
{
	if (input.empty())
	{
		std::cerr << "Error: Empty input." << std::endl;
		return;
	}
	std::string value = (input.back() == 'f') ? input.substr(0, input.size() - 1) : input;
	double num = atof(value.c_str());
	toChar(num);
	toInt(num);
	toFloat(num);
	toDouble(num);
}
