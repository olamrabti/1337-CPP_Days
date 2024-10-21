#include "Fixed.hpp"

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
        this->_value = rhs.getRawBits();
    return *this;
}

std::ostream &Fixed::operator<<(std::ostream &os) const
{
    os << this->getRawBits();
    return os;
}

Fixed::Fixed(const int integer) : _value(integer)
{
    this->_value = integer << this->_fixed_pt;
}

Fixed::Fixed(const float fl_num)
{
    this->_value = static_cast<int>(roundf(fl_num * (1 << this->_fixed_pt)));
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_value;
}

void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}
float Fixed::toFloat(void) const
{
    return (static_cast<float>(this->_value) / (1 << this->_fixed_pt));
}

int Fixed::toInt(void) const
{
    return (this->_value >> this->_fixed_pt);
}