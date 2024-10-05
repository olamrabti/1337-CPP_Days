#ifndef CONTACT_CLASS_HPP
#define CONTACT_CLASS_HPP

#include <string>

class Contact
{
private:
    std::size_t index;
    std::string first_name;
    std::string last_name;
    std::string nick_name;
    std::string phone_number;
    std::string darkest_secret;

public:
    void set_index(std::size_t index);
    void set_firstname(std::string firstname);
    void set_lastname(std::string lastname);
    void set_nickname(std::string nickname);
    void set_phonenumber(std::string phonenum);
    void set_secret(std::string secret);
    std::size_t get_index(void);
    std::string get_firstname(void);
    std::string get_lastname(void);
    std::string get_nickname(void);
    std::string get_phonenumber(void);
    std::string get_secret(void);
};

#endif