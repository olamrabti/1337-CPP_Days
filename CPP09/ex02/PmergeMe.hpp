#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#include <exception>
#include <cstdlib>
#include <cmath>

void mergeInsertionSortVector(std::vector<int> &arr);
void mergeSortVector(std::vector<int> &arr, std::vector<int> &sorted);
void insertSortVector(std::vector<int> &sorted, int element);
void insertSortDeque(std::deque<int> &sorted, int element);
void mergeSortDeque(std::deque<int> &arr, std::deque<int> &sorted);
void mergeInsertionSortDeque(std::deque<int> &arr);
std::vector<int> generateJacobSequence(size_t size);
void parse(int ac, char **av, std::vector<int> &vec);
template <typename Container>
void printContent(const Container &container, std::string title)
{
    std::cout << title;
    for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

#endif