#include "iter.hpp"

void my_bzero(int &element)
{
    element = 0;
}

void printElement(int element)
{
    std::cout << element << " ";
}

template <typename T>
void print(const T &element)
{
    std::cout << element << " ";
}

int main()
{
    std::cout << "--------------- Test1 with int array : --------------- " << std::endl;
    int test[] = {10, 20, 30, 40, 50};
    size_t size = sizeof(test) / sizeof(int);

    std::cout << "Original array: " << std::endl;
    iter(test, size, printElement);
    std::cout << std::endl;

    std::cout << "Original array (with print<int>): " << std::endl;
    iter(test, size, print<int>); // TODO learn more about this syntax <int>
    std::cout << std::endl;

    std::cout << "Set All elements to 0 :" << std::endl;
    iter(test, size, my_bzero);
    iter(test, size, printElement);
    std::cout << std::endl;

    std::cout << "--------------- Test1 with string array : ------------- " << std::endl;
    std::string test2[] = {"str1", "str2", "str3", "str4", "str5"};
    size_t size2 = sizeof(test2) / sizeof(std::string);

    std::cout << "Original array (with print<string>): " << std::endl;
    iter(test2, size2, print<std::string>);
    std::cout << std::endl;

    return 0;
}
