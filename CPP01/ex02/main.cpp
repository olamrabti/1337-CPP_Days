#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR;
    std::string &stringREF = str;

    stringPTR = &str;
    std::cout << "Addresses : \n"
              << &str << std::endl
              << &(*stringPTR) << std::endl
              << &stringREF << std::endl;
    std::cout << "Values : \n"
              << str << std::endl
              << *stringPTR << std::endl
              << stringREF << std::endl;
    return 0;
}