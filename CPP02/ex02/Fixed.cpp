#include "Fixed.hpp"

const int Fixed::_fixed_pt = 8;

Fixed::Fixed() : _value(0) {};

Fixed::Fixed(const Fixed &src)
{
    *this = src;
};

Fixed &Fixed::operator=(const Fixed &rhs)
{
    if (this != &rhs)
        _value = rhs.getRawBits();
    return *this;
};

Fixed::Fixed(const int integer)
{
    _value = integer << _fixed_pt;
};

Fixed::Fixed(const float fl_num)
{
    _value = (int)(roundf(fl_num * (1 << _fixed_pt)));
};

std::ostream &operator<<(std::ostream &os, Fixed const &pt)
{
    os << pt.toFloat();
    return os;
};

Fixed::~Fixed() {};

int Fixed::getRawBits(void) const
{
    return _value;
};

void Fixed::setRawBits(int const raw)
{
    _value = raw;
};
float Fixed::toFloat(void) const
{
    return ((float)(_value) / (1 << _fixed_pt));
};

int Fixed::toInt(void) const
{
    return (_value >> _fixed_pt);
};

bool Fixed::operator>(const Fixed &rsh) const
{
    return _value > rsh._value;
};

bool Fixed::operator<(const Fixed &rsh) const
{
    return _value < rsh._value;
};

bool Fixed::operator>=(const Fixed &rsh) const
{
    return _value >= rsh._value;
};

bool Fixed::operator<=(const Fixed &rsh) const
{
    return _value <= rsh._value;
};

bool Fixed::operator==(const Fixed &rsh) const
{
    return _value == rsh._value;
};

bool Fixed::operator!=(const Fixed &rsh) const
{
    return _value != rsh._value;
};

Fixed Fixed::operator+(const Fixed &rsh) const
{
    return Fixed(toFloat() + rsh.toFloat());
};

Fixed Fixed::operator-(const Fixed &rsh) const
{
    return Fixed(toFloat() - rsh.toFloat());
};

Fixed Fixed::operator-(void) const
{
    return Fixed(-toInt());
};

Fixed Fixed::operator*(const Fixed &rsh) const
{
    Fixed result;
    result.setRawBits((_value * rsh._value) / (1 << _fixed_pt));
    return result;
};

Fixed Fixed::operator/(const Fixed &rsh) const
{
    Fixed result;
    result.setRawBits((_value * (1 << _fixed_pt)) / rsh._value);
    return result;
};

Fixed &Fixed::operator++(void)
{
    _value++;
    return *this;
};

Fixed &Fixed::operator--(void)
{
    _value--;
    return *this;
};

Fixed Fixed::operator++(int)
{
    Fixed old;
    old = *this;
    _value++;
    return old;
};

Fixed Fixed::operator--(int)
{
    Fixed old;
    old = *this;
    _value--;
    return old;
};

Fixed &Fixed::min(Fixed &f1, Fixed &f2)
{
    if (f1 < f2)
        return f1;
    return f2;
};

Fixed const &Fixed::min(const Fixed &f1, const Fixed &f2)
{
    if (f1 < f2)
        return f1;
    return f2;
};

Fixed &Fixed::max(Fixed &f1, Fixed &f2)
{
    return ((f1 < f2) ? f2 : f1);
};

Fixed const &Fixed::max(const Fixed &f1, const Fixed &f2)
{
    return ((f1 < f2) ? f2 : f1);
};
