#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern
{
private:
	AForm *createRRF(std::string target);
	AForm *createPPF(std::string target);
	AForm *createSCF(std::string target);

public:
	Intern(void);
	Intern(Intern const &copy);
	~Intern(void);
	Intern const &operator=(Intern const &rhs);
	AForm *makeForm(std::string name, std::string target);
};

#endif