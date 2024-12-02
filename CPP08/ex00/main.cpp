#include "easyfind.hpp"
#include <vector>
#include <list>

int main()
{
    try
    {
        std::vector<int> numbers;
        numbers.push_back(1);
        numbers.push_back(2);
        numbers.push_back(3);
        numbers.push_back(4);
        numbers.push_back(5);

        std::cout << "Searching for (3) in vector { ";
        for (size_t i = 0; i < numbers.size(); ++i)
        {
            std::cout << numbers[i] << " ";
        }
        std::cout << "}\n"
                  << easyfind(numbers, 3) << std::endl;

        std::list<int> lst;
        lst.push_back(10);
        lst.push_back(20);
        lst.push_back(30);
        lst.push_back(40);
        lst.push_back(50);

        std::cout << "Searching for (20) in list { ";
        for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
        {
            std::cout << *it << " ";
        }
        std::cout << "} \n"
                  << easyfind(lst, 20) << std::endl;

        std::cout << "Searching for (80) in list {10, 20, 30, 40, 50} : \n"
                  << easyfind(lst, 80) << std::endl;
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}