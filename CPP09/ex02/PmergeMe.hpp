#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <ctime>
#include <exception>

void mergeInsertionSortVector(std::vector<int> &arr);
void mergeSortVector(std::vector<int> &arr, std::vector<int> &sorted);
void insertSortVector(std::vector<int> &sorted, int element);
void insertSortList(std::list<int> &sorted, int element);
void mergeSortList(std::list<int> &arr, std::list<int> &sorted);
void mergeInsertionSortList(std::list<int> &arr);
std::vector<int> generateJacobSequence(size_t size);
std::vector<int> parse(int ac, char **av);

#endif