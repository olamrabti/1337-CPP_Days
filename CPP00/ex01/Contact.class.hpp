
#ifndef CONTACT_CLASS_HPP
#define CONTACT_CLASS_HPP

#include <iostream>
#include <iomanip>

class Contact
{
private:
    std::size_t _index;
    std::string _first_name;
    std::string _last_name;
    std::string _nick_name;
    std::string _phone_number;
    std::string _darkest_secret;

public:
    Contact();
    ~Contact();
    void set_index(std::size_t index);
    void set_firstname(std::string firstname);
    void set_lastname(std::string lastname);
    void set_nickname(std::string nickname);
    void set_phonenumber(std::string phonenum);
    void set_secret(std::string secret);
    std::size_t get_index(void) const;
    std::string get_firstname(void) const;
    std::string get_lastname(void) const;
    std::string get_nickname(void) const;
    std::string get_phonenumber(void) const;
    std::string get_secret(void) const;
    void display_contact(void) const;
};

#endif