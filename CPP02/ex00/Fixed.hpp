#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
public:
    Fixed();
    Fixed(const Fixed &src);
    Fixed &operator=(const Fixed &rsh);
    ~Fixed();
    int getRawBits(void) const;
    void setRawBits(int const raw);

private:
    int _value;
    static const int _fixed_pt = 8;
};
#endif