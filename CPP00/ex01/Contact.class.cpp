#include "Contact.class.hpp"

void Contact::set_firstname(std::string firstname)
{
    _first_name = firstname;
};
void Contact::set_lastname(std::string lastname)
{
    _last_name = lastname;
};

void Contact::set_nickname(std::string nickname)
{
    _nick_name = nickname;
};

void Contact::set_phonenumber(std::string phonenum)
{
    _phone_number = phonenum;
};

void Contact::set_secret(std::string secret)
{
    _darkest_secret = secret;
};

Contact::Contact() : _index(99), _first_name(""),
                     _last_name(""),
                     _nick_name(""),
                     _phone_number(""),
                     _darkest_secret("") {};
Contact::~Contact() {
};

void Contact::set_index(std::size_t index)
{
    _index = index;
};

std::string Contact::get_firstname(void) const
{
    return _first_name;
};
std::string Contact::get_lastname(void) const
{
    return _last_name;
};

std::string Contact::get_nickname(void) const
{
    return _nick_name;
};

std::string Contact::get_phonenumber(void) const
{

    return _phone_number;
};

std::string Contact::get_secret(void) const
{
    return _darkest_secret;
}
void Contact::display_contact(void) const
{
    std::cout << "   First Name: " << _first_name << std::endl;
    std::cout << "   Last Name: " << _last_name << std::endl;
    std::cout << "   Nickname: " << _nick_name << std::endl;
    std::cout << "   Phone Number: " << _phone_number << std::endl;
    std::cout << "   Darkest Secret: " << _darkest_secret << std::endl;
};
std::size_t Contact::get_index(void) const
{
    return _index;
};
