#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
public:
    Fixed();
    Fixed(const int integer);
    Fixed(const float integer);
    Fixed(const Fixed &src);
    Fixed &operator=(const Fixed &rsh);
    ~Fixed();
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;

private:
    int _value;
    static const int _fixed_pt = 8;
};
std::ostream &operator<<(std::ostream &os, const Fixed &pt);
#endif