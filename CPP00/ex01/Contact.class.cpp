#include "Contact.class.hpp"

void Contact::set_firstname(std::string firstname)
{
    this->_first_name = firstname;
};
void Contact::set_lastname(std::string lastname)
{
    this->_last_name = lastname;
};

void Contact::set_nickname(std::string nickname)
{
    this->_nick_name = nickname;
};

void Contact::set_phonenumber(std::string phonenum)
{
    this->_phone_number = phonenum;
};

void Contact::set_secret(std::string secret)
{
    this->_darkest_secret = secret;
};

void Contact::set_index(std::size_t index)
{
    this->_index = index;
};

std::string Contact::get_firstname(void) const
{
    return this->_first_name;
};
std::string Contact::get_lastname(void) const
{
    return this->_last_name;
};

std::string Contact::get_nickname(void) const
{
    return this->_nick_name;
};

std::string Contact::get_phonenumber(void) const
{

    return this->_phone_number;
};

std::string Contact::get_secret(void) const
{
    return this->_darkest_secret;
};
std::size_t Contact::get_index(void) const
{
    return this->_index;
};
