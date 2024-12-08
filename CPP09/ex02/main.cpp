
#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    try
    {
        std::vector<int> vec;
        vec = parse(ac, av);

        // std::list<int> lst;
        // lst.push_back(5);
        // lst.push_back(2);
        // lst.push_back(9);
        // lst.push_back(4);
        // lst.push_back(7);

        // std::cout << "Original list: ";
        // for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
        //     std::cout << *it << " ";
        // std::cout << std::endl;

        clock_t start = clock(); // TODO should i include variable declaration ?
        // mergeInsertionSortList(lst);
        clock_t end = clock();

        // std::cout << "Sorted list: ";
        // for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
        //     std::cout << *it << " ";
        // std::cout << std::endl;

        // std::cout << "List sort time: "
        //           << ((end - start) * 1000000.0) / CLOCKS_PER_SEC
        //           << " us" << std::endl;

        // std::vector<int> vec;
        // vec.push_back(5);
        // vec.push_back(2);
        // vec.push_back(9);
        // vec.push_back(4);
        // vec.push_back(7);
        // vec.push_back(23);
        // vec.push_back(3);
        // vec.push_back(1);
        // vec.push_back(10);
        // vec.push_back(67);

        std::cout << "Original vector: ";
        for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;

        start = clock();
        mergeInsertionSortVector(vec);
        end = clock();

        std::cout << "Sorted vector: ";
        for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;

        std::cout << "Vector sort time: "
                  << ((end - start) * 1000000.0) / CLOCKS_PER_SEC
                  << " us" << std::endl;
    }
    catch (const std::exception &e)
    {
    }

    return 0;
}
