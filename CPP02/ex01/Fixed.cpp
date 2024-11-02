#include "Fixed.hpp"

const int Fixed::_fixed_pt = 8;

Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        _value = rhs.getRawBits();
    return *this;
}

Fixed::Fixed(const int integer) : _value(integer)
{
    std::cout << "Int constructor called" << std::endl;
    _value = integer << _fixed_pt;
}

Fixed::Fixed(const float fl_num)
{
    std::cout << "Float constructor called" << std::endl;
    _value = (int)(roundf(fl_num * (1 << _fixed_pt)));
}

std::ostream &operator<<(std::ostream &os, Fixed const &pt)
{
    os << pt.toFloat();
    return os;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    return _value;
}

void Fixed::setRawBits(int const raw)
{
    _value = raw;
}
float Fixed::toFloat(void) const
{
    return ((float)(_value) / (1 << _fixed_pt));
}

int Fixed::toInt(void) const
{
    return (_value >> _fixed_pt);
}
