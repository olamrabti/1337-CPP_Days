#include "PmergeMe.hpp"

std::vector<int> generateJacobSequence(size_t size)
{
	std::vector<int> jacob;
	jacob.push_back(0);
	if (size == 0)
		return jacob;
	jacob.push_back(1);
	for (size_t i = 2; i <= size; ++i)
	{
		jacob.push_back(jacob[i - 1] + 2 * jacob[i - 2]);
	}
	return jacob;
}

void insertSortVector(std::vector<int> &sorted, int element)
{
	std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), element);
	sorted.insert(pos, element);
}

void mergeSortVector(std::vector<int> &arr, std::vector<int> &sorted)
{
	if (!arr.size())
		return;
	int unpaired = arr.back();

	if (arr.size() == 1)
	{
		insertSortVector(sorted, arr[0]);
		return;
	}
	std::vector<int> larger;
	std::vector<int> smaller;
	std::vector<int> tmpSorted;

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
	if (smaller.size() > 2)
	{
		larger.insert(larger.begin(), smaller.front());
		smaller.erase(smaller.begin());
	}
	if (!larger.empty())
		mergeSortVector(larger, tmpSorted);
	if (arr.size() % 2 != 0)
		insertSortVector(tmpSorted, unpaired);
	if (!smaller.empty())
		mergeSortVector(smaller, tmpSorted);
	std::vector<int> jacob = generateJacobSequence(tmpSorted.size());
	for (size_t i = 0; i < jacob.size(); i++)
	{
		if (jacob[i] < static_cast<int>(tmpSorted.size()))
		{
			for (size_t j = jacob[i]; tmpSorted.size(); j++)
			{
				insertSortVector(sorted, tmpSorted[jacob[i]]);
				tmpSorted.erase(tmpSorted.begin() + jacob[i]);
			}
		}
		jacob = generateJacobSequence(tmpSorted.size());
	}
}

void mergeInsertionSortVector(std::vector<int> &arr)
{
	if (arr.size() < 2)
		return;

	std::vector<int> sorted;
	mergeSortVector(arr, sorted);
	arr = sorted;
}

void parse(int ac, char **av, std::vector<int> &vec)
{

	for (int i = 1; i < ac; i++)
	{

		double value = std::atof(av[i]);

		if (value < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			throw std::runtime_error("");
		}

		if (value > INT_MAX)
		{
			std::cerr << "Error: too large number." << std::endl;
			throw std::runtime_error("");
		}
		vec.push_back(value);
	}
}

void insertSortdeque(std::deque<int> &sorted, int element)
{
	std::deque<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), element);
	sorted.insert(pos, element);
}

void mergeSortdeque(std::deque<int> &arr, std::deque<int> &sorted)
{
	if (!arr.size())
		return;
	int unpaired = arr.back();

	if (arr.size() == 1)
	{
		insertSortdeque(sorted, arr[0]);
		return;
	}
	std::deque<int> larger;
	std::deque<int> smaller;
	std::deque<int> tmpSorted;

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
	if (smaller.size() > 2)
	{
		larger.insert(larger.begin(), smaller.front());
		smaller.erase(smaller.begin());
	}
	if (!larger.empty())
		mergeSortdeque(larger, tmpSorted);
	if (arr.size() % 2 != 0)
		insertSortdeque(tmpSorted, unpaired);
	if (!smaller.empty())
		mergeSortdeque(smaller, tmpSorted);
	std::vector<int> jacob = generateJacobSequence(tmpSorted.size());
	for (size_t i = 0; i < jacob.size(); i++)
	{
		if (jacob[i] < static_cast<int>(tmpSorted.size()))
		{
			for (size_t j = jacob[i]; tmpSorted.size(); j++)
			{
				insertSortdeque(sorted, tmpSorted[jacob[i]]);
				tmpSorted.erase(tmpSorted.begin() + jacob[i]);
			}
		}
		jacob = generateJacobSequence(tmpSorted.size());
	}
}

void mergeInsertionSortdeque(std::deque<int> &arr)
{
	if (arr.size() < 2)
		return;

	std::deque<int> sorted;
	mergeSortdeque(arr, sorted);
	arr = sorted;
}
