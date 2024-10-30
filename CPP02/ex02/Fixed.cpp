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
        this->_value = rhs.getRawBits();
    return *this;
};

Fixed::Fixed(const int integer)
{
    this->_value = integer << this->_fixed_pt;
};

Fixed::Fixed(const float fl_num)
{
    this->_value = (int)(roundf(fl_num * (1 << this->_fixed_pt)));
};

std::ostream &operator<<(std::ostream &os, Fixed const &pt)
{
    os << pt.toFloat();
    return os;
};

Fixed::~Fixed() {};

int Fixed::getRawBits(void) const
{
    return this->_value;
};

void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
};
float Fixed::toFloat(void) const
{
    return ((float)(this->_value) / (1 << this->_fixed_pt));
};

int Fixed::toInt(void) const
{
    return (this->_value >> this->_fixed_pt);
};

bool Fixed::operator>(const Fixed &rsh) const
{
    return this->_value > rsh._value;
};

bool Fixed::operator<(const Fixed &rsh) const
{
    return this->_value < rsh._value;
};

bool Fixed::operator>=(const Fixed &rsh) const
{
    return this->_value >= rsh._value;
};

bool Fixed::operator<=(const Fixed &rsh) const
{
    return this->_value <= rsh._value;
};

bool Fixed::operator==(const Fixed &rsh) const
{
    return this->_value == rsh._value;
};

bool Fixed::operator!=(const Fixed &rsh) const
{
    return this->_value != rsh._value;
};

Fixed Fixed::operator+(const Fixed &rsh) const
{
    return Fixed(this->toFloat() + rsh.toFloat());
};

Fixed Fixed::operator-(const Fixed &rsh) const
{
    return Fixed(this->toFloat() - rsh.toFloat());
};

Fixed Fixed::operator-(void) const
{
    return Fixed(-this->toInt());
};

Fixed Fixed::operator*(const Fixed &rsh) const
{
    Fixed result;
    result.setRawBits((this->_value * rsh._value) / (1 << this->_fixed_pt));
    return result;
};

Fixed Fixed::operator/(const Fixed &rsh) const
{
    Fixed result;
    result.setRawBits((this->_value * (1 << this->_fixed_pt)) / rsh._value);
    return result;
};

Fixed &Fixed::operator++(void)
{
    this->_value++;
    return *this;
};

Fixed &Fixed::operator--(void)
{
    this->_value--;
    return *this;
};

Fixed Fixed::operator++(int)
{
    Fixed old;
    old = *this;
    this->_value++;
    return old;
};

Fixed Fixed::operator--(int)
{
    Fixed old;
    old = *this;
    this->_value--;
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
