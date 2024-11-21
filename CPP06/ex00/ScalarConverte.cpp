#include "ScalarConverte.hpp"

ScalarConverte::ScalarConverte(void) {}

ScalarConverte::ScalarConverte(ScalarConverte const &copy)
{
	*this = copy;
}

ScalarConverte::~ScalarConverte(void) {}

bool isValidInt(const std::string &str)
{
	size_t i = (str[0] == '-') ? 1 : 0;
	while (i < str.size())
	{
		if (!isdigit(str[i]))
			return false;
		i++;
	}
	return true;
}
void ScalarConverte::convert(std::string str)
{
	if (str.empty())
		std::cerr << "Invalid Input" << std::endl;
	std::cout << "char : " << static_cast<char>(str[0]) << std::endl;
	if (isValidInt(str))
	{
		int value = atoi(str.c_str());
		std::cout << "Int: " << value << std::endl;
	}
	else
	{
		std::cout << "Int: impossible" << std::endl;
	}
	std::cout << "float : " << std::endl;
	std::cout << "double : " << std::endl;
}

ScalarConverte const &ScalarConverte::operator=(ScalarConverte const &rhs)
{
	return (*this);
}