#include <iostream>
#include <vector>
#include <list>
#include <algorithm> // For std::lower_bound
#include <ctime>     // For timing

void mergeInsertionSortVector(std::vector<int> &arr);
void mergeInsertionSortList(std::list<int> &arr);
void recursiveSortVector(std::vector<int> &arr, std::vector<int> &sorted);
void recursiveSortList(std::list<int> &arr, std::list<int> &sorted);
void binaryInsertVector(std::vector<int> &sorted, int element);
void binaryInsertList(std::list<int> &sorted, int element);
std::vector<int> generateJacobsthalSequence(size_t size);

int main()
{
    // Example with std::list
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(2);
    lst.push_back(9);
    lst.push_back(4);
    lst.push_back(7);

    std::cout << "Original list: ";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    clock_t start = clock();
    mergeInsertionSortList(lst);
    clock_t end = clock();

    std::cout << "Sorted list: ";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << "List sort time: "
              << ((end - start) * 1000000.0) / CLOCKS_PER_SEC
              << " us" << std::endl;

    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(2);
    vec.push_back(9);
    vec.push_back(4);
    vec.push_back(7);

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

    return 0;
}

void mergeInsertionSortVector(std::vector<int> &arr)
{
    if (arr.size() <= 1)
        return;
    std::vector<int> sorted;
    recursiveSortVector(arr, sorted);
    arr = sorted;
}

void mergeInsertionSortList(std::list<int> &arr)
{
    if (arr.size() <= 1)
        return;
    std::list<int> sorted;
    recursiveSortList(arr, sorted);
    arr = sorted;
}

void recursiveSortVector(std::vector<int> &arr, std::vector<int> &sorted)
{
    size_t n = arr.size();
    if (n == 0)
        return;

    std::vector<int> larger, smaller;

    for (size_t i = 0; i + 1 < arr.size(); i += 2)
    {
        if (arr[i] > arr[i + 1])
        {
            larger.push_back(arr[i]);
            smaller.push_back(arr[i + 1]);
        }
        else
        {
            larger.push_back(arr[i + 1]);
            smaller.push_back(arr[i]);
        }
    }

    if (arr.size() % 2 != 0)
        smaller.push_back(arr.back());

    std::vector<int> sortedLarger;
    recursiveSortVector(larger, sortedLarger);

    sorted.push_back(smaller.front());
    std::vector<int> jacobsthal = generateJacobsthalSequence(smaller.size() - 1);

    for (size_t i = 1; i < smaller.size(); ++i)
    {
        binaryInsertVector(sorted, smaller[jacobsthal[i - 1]]);
    }

    for (size_t i = 0; i < sortedLarger.size(); ++i)
    {
        binaryInsertVector(sorted, sortedLarger[i]);
    }
}

void recursiveSortList(std::list<int> &arr, std::list<int> &sorted)
{
    if (arr.size() <= 1)
        return;

    std::list<int> larger, smaller;

    std::list<int>::iterator it = arr.begin();
    while (it != arr.end())
    {
        std::list<int>::iterator next = it;
        ++next;
        if (next != arr.end() && *it > *next)
        {
            larger.push_back(*it);
            smaller.push_back(*next);
        }
        else if (next != arr.end())
        {
            larger.push_back(*next);
            smaller.push_back(*it);
        }
        else
        {
            smaller.push_back(*it);
        }
        if (next != arr.end())
            ++it;
        ++it;
    }

    std::list<int> sortedLarger;
    recursiveSortList(larger, sortedLarger);

    sorted.push_back(smaller.front());
    smaller.pop_front();

    std::vector<int> jacobsthal = generateJacobsthalSequence(smaller.size());

    for (size_t i = 0; i < jacobsthal.size(); ++i)
    {
        std::list<int>::iterator it_smaller = smaller.begin();
        size_t index = jacobsthal[i];
        while (index-- > 0)
            ++it_smaller;
        binaryInsertList(sorted, *it_smaller);
    }

    for (std::list<int>::iterator it = sortedLarger.begin(); it != sortedLarger.end(); ++it)
    {
        binaryInsertList(sorted, *it);
    }
}

void binaryInsertVector(std::vector<int> &sorted, int element)
{
    std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), element);
    sorted.insert(pos, element);
}

void binaryInsertList(std::list<int> &sorted, int element)
{
    std::list<int>::iterator pos = sorted.begin();
    for (; pos != sorted.end(); ++pos)
    {
        if (*pos >= element)
            break;
    }
    sorted.insert(pos, element);
}

std::vector<int> generateJacobsthalSequence(size_t size)
{
    std::vector<int> jacobsthal;
    jacobsthal.push_back(0);
    if (size == 0)
        return jacobsthal;
    jacobsthal.push_back(1);
    for (size_t i = 2; i <= size; ++i)
    {
        jacobsthal.push_back(jacobsthal[i - 1] + 2 * jacobsthal[i - 2]);
    }
    return jacobsthal;
}
