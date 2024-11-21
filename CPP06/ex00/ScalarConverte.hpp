#ifndef SCALARCONVERTE_HPP
#define SCALARCONVERTE_HPP

#include <iostream>

class ScalarConverte
{
private:
	ScalarConverte(void);
	ScalarConverte(ScalarConverte const &copy);
	ScalarConverte const &operator=(ScalarConverte const &rhs);

public:
	~ScalarConverte(void);
	static void convert(std::string str);
};

#endif