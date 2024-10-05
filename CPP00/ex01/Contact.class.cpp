#include "Contact.class.hpp"

void Contact::set_firstname(std::string firstname)
{
    this->first_name = firstname;
};
void Contact::set_lastname(std::string lastname)
{
    this->last_name = lastname;
};

void Contact::set_nickname(std::string nickname)
{
    this->nick_name = nickname;
};

void Contact::set_phonenumber(std::string phonenum)
{
    this->phone_number = phonenum;
};

void Contact::set_secret(std::string secret)
{
    this->darkest_secret = secret;
};

void Contact::set_index(std::size_t index)
{
    this->index = index;
};

std::string Contact::get_firstname(void)
{
    return this->first_name;
};
std::string Contact::get_lastname(void)
{
    return this->last_name;
};

std::string Contact::get_nickname(void)
{
    return this->nick_name;
};

std::string Contact::get_phonenumber(void)
{

    return this->phone_number;
};

std::string Contact::get_secret(void)
{
    return this->darkest_secret;
};
std::size_t Contact::get_index(void)
{
    return this->index;
};
