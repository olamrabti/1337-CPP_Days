
#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    try
    {
        std::vector<int> tmp;
        clock_t start; // TODO should i include variable declaration ? yes
        clock_t end;

        parse(ac, av, tmp);

        printContent(tmp, "Before : ");

        start = clock();
        std::vector<int> vec;
        vec.insert(vec.begin(), tmp.begin(), tmp.end());
        mergeInsertionSortVector(vec);
        end = clock();

        printContent(vec, "After : ");

        std::cout << "Time to process a range of " << tmp.size() << " elements with std::vector : "
                  << static_cast<double>((end - start) * 1000000.0) / CLOCKS_PER_SEC
                  << " us" << std::endl;

        start = clock();
        std::deque<int> deq;
        deq.insert(deq.begin(), vec.begin(), vec.end());
        mergeInsertionSortdeque(deq);
        end = clock();

        std::cout << "Time to process a range of " << tmp.size() << " elements with std::deque : "
                  << static_cast<double>((end - start) * 1000000.0) / CLOCKS_PER_SEC
                  << " us" << std::endl;
    }
    catch (const std::exception &e)
    {
    }

    return 0;
}
