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
    bool operator>(const Fixed &rsh) const;
    bool operator<(const Fixed &rsh) const;
    bool operator>=(const Fixed &rsh) const;
    bool operator<=(const Fixed &rsh) const;
    bool operator==(const Fixed &rsh) const;
    bool operator!=(const Fixed &rsh) const;
    Fixed operator+(const Fixed &rsh) const;
    Fixed operator-(const Fixed &rsh) const;
    Fixed operator-(void) const;
    Fixed operator*(const Fixed &rsh) const;
    Fixed operator/(const Fixed &rsh) const;
    Fixed &operator++(void);
    Fixed &operator--(void);
    Fixed operator++(int);
    Fixed operator--(int);
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
    static Fixed &min(Fixed &f1, Fixed &f2);
    static const Fixed &min(const Fixed &f1, const Fixed &f2);
    static Fixed &max(Fixed &f1, Fixed &f2);
    static const Fixed &max(const Fixed &f1, const Fixed &f2);

private:
    int _value;
    static const int _fixed_pt;
};
std::ostream &operator<<(std::ostream &os, const Fixed &pt);
#endif