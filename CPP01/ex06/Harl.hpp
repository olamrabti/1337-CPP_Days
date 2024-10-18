#ifndef HARL_CLASS_HPP
#define HARL_CLASS_HPP

#define SUCCESS 0
#define FAILURE 1

#include <iostream>
#include <fstream>
#include <string>

class Harl
{
private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);

public:
    void complain(std::string level);
};

#endif