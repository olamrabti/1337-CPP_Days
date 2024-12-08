#include "PmergeMe.hpp"

template <typename Container>
void printContent(const Container &container, std::string title)
{
	std::cout << title << std::endl;
	for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

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

// void mergeSortVector(std::vector<int> &arr, std::vector<int> &sorted)
// {
// 	static int count = 1;
// 	size_t n = arr.size();
// 	if (n == 0)
// 		return;

// 	std::vector<int> larger;
// 	std::vector<int> smaller;

// 	for (size_t i = 0; i + 1 < arr.size(); i += 2)
// 	{
// 		if (arr[i] > arr[i + 1])
// 		{
// 			larger.push_back(arr[i]);
// 			smaller.push_back(arr[i + 1]);
// 		}
// 		else
// 		{
// 			larger.push_back(arr[i + 1]);
// 			smaller.push_back(arr[i]);
// 		}
// 	}

// 	if (arr.size() % 2 != 0)
// 		count = arr.back();
// 	if (arr.size() % 2 != 0)
// 		smaller.push_back(arr.back());

// 	std::cout << "arr size : " << arr.size() << std::endl;
// 	printContent(smaller, "smaller :");
// 	printContent(larger, "larger :");
// 	std::vector<int> sortedLarger;
// 	mergeSortVector(larger, sortedLarger);
// 	printContent(sortedLarger, "sorted larger :");

// 	sorted.push_back(smaller.front());
// 	std::vector<int> jacob = generateJacobSequence(smaller.size() - 1);

// 	for (size_t i = 1; i < smaller.size(); ++i)
// 	{
// 		insertSortVector(sorted, smaller[jacob[i - 1]]);
// 	}

// 	for (size_t i = 0; i < sortedLarger.size(); ++i)
// 	{
// 		insertSortVector(sorted, sortedLarger[i]);
// 	}
// }

// void mergeInsertionSortVector(std::vector<int> &arr)
// {
// 	if (arr.size() <= 1)
// 		return;
// 	std::vector<int> sorted;
// 	printContent(sorted, "sorted : ");
// 	mergeSortVector(arr, sorted);
// 	printContent(sorted, "sorted : ");
// 	arr = sorted;
// }

// ================================================== List ======================================

// void insertSortList(std::list<int> &sorted, int element)
// {
// 	std::list<int>::iterator pos = sorted.begin();
// 	while (pos != sorted.end())
// 	{
// 		if (*pos >= element)
// 			break;
// 		pos++;
// 	}
// 	sorted.insert(pos, element);
// }

// void mergeSortList(std::list<int> &arr, std::list<int> &sorted)
// {
// 	if (arr.size() <= 1)
// 		return;

// 	std::list<int> larger;
// 	std::list<int> smaller;

// 	std::list<int>::iterator it = arr.begin();
// 	while (it != arr.end())
// 	{
// 		std::list<int>::iterator next = it;
// 		++next;
// 		if (next != arr.end() && *it > *next)
// 		{
// 			larger.push_back(*it);
// 			smaller.push_back(*next);
// 		}
// 		else if (next != arr.end())
// 		{
// 			larger.push_back(*next);
// 			smaller.push_back(*it);
// 		}
// 		else
// 		{
// 			smaller.push_back(*it);
// 		}
// 		if (next != arr.end())
// 			++it;
// 		++it;
// 	}

// 	std::list<int> sortedLarger;
// 	mergeSortList(larger, sortedLarger);

// 	sorted.push_back(smaller.front());
// 	smaller.pop_front();

// 	std::vector<int> jacob = generateJacobSequence(smaller.size());

// 	// for (size_t i = 0; i < jacob.size(); ++i)
// 	// {
// 	// 	std::list<int>::iterator it_s = smaller.begin();
// 	// 	size_t index = jacob[i];
// 	// 	while (index-- > 0)
// 	// 		++it_s;
// 	// 	insertSortList(sorted, *it_s);
// 	// }

// 	// for (std::list<int>::iterator it = sortedLarger.begin(); it != sortedLarger.end(); ++it)
// 	// {
// 	// 	insertSortList(sorted, *it);
// 	// }
// }
// void mergeInsertionSortList(std::list<int> &arr)
// {
// 	if (arr.size() <= 1)
// 		return;
// 	std::list<int> sorted;
// 	mergeSortList(arr, sorted);
// 	arr = sorted;
// }

void mergeSortVector(std::vector<int> &arr, std::vector<int> &sorted)
{
	if (!arr.size())
		return;
	int unpaired = -1;
	std::vector<int> larger;
	std::vector<int> smaller;
	std::vector<int> sortedLarger;

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

	if (larger.size() == arr.size() / 2)
	{
		sortedLarger.insert(sortedLarger.end(), larger.begin(), larger.end());
		sorted.push_back(smaller.front());
		smaller.erase(smaller.begin());
		if (smaller.size() % 2 != 0)
		{
			unpaired = smaller.back();
			smaller.pop_back();
		}
	}
	if (!smaller.empty())
		mergeSortVector(smaller, sortedLarger);

	std::vector<int> jacob = generateJacobSequence(sortedLarger.size());
	while (sortedLarger.size())
	{
		jacob = generateJacobSequence(sortedLarger.size());
		for (size_t i = 0; i < jacob.size(); ++i)
		{
			if (jacob[i] < static_cast<int>(sortedLarger.size()))
			{
				insertSortVector(sorted, sortedLarger[jacob[i]]);
				sortedLarger.erase(sortedLarger.begin() + jacob[i]);
			}
		}
	}
	if (unpaired > 0)
		insertSortVector(sorted, unpaired);
}

void mergeInsertionSortVector(std::vector<int> &arr)
{
	if (arr.size() < 2)
		return;
	std::vector<int> sorted;
	std::vector<int> copy = arr;
	int unpaired = -1;
	if (arr.size() % 2 != 0)
	{
		unpaired = arr.back();
		mergeSortVector(copy, sorted);
		copy.pop_back();
		insertSortVector(sorted, unpaired);
	}
	else
		mergeSortVector(copy, sorted);
	arr = sorted;
}

std::vector<int> parse(int ac, char **av)
{

	std::vector<int> tmp;
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
			std::cerr << "Error: too large a number." << std::endl;
			throw std::runtime_error("");
		}
		tmp.push_back(value);
	}
	return tmp;
}