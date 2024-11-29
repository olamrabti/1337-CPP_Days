#include "easyfind.hpp"
#include <vector>
#include <list>

int main()
{
    try
    {
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(4);
        vec.push_back(5);

        std::cout << "Searching for (3) in vector {1, 2, 3, 4, 5} : \n"
                  << easyfind(vec, 3) << std::endl;

        std::list<int> lst;
        lst.push_back(10);
        lst.push_back(20);
        lst.push_back(30);
        lst.push_back(40);
        lst.push_back(50);

        std::cout << "Searching for (20) in list {10, 20, 30, 40, 50} : \n"
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