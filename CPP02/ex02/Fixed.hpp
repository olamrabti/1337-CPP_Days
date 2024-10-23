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
    Fixed &operator++(void); // increments by epsillon
    Fixed &operator--(void);
    Fixed operator++(int); // int is a dummy parameter to differenciate beetween post and pre. alwys = 0;
    Fixed operator--(int);
    ~Fixed();
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
    static const int _fixed_pt = 8;
};
std::ostream &operator<<(std::ostream &os, const Fixed &pt);
#endif