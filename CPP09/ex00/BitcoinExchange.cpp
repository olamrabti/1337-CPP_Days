#include "BitcoinExchange.hpp"
#include <sstream>

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
{
	*this = src;
}

BitcoinExchange::~BitcoinExchange(void) {}

BitcoinExchange const &BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
	if (this != &rhs)
		_data = rhs._data;
	return (*this);
}

void BitcoinExchange::store_data(void)
{
	std::ifstream data("data.csv");
	if (data.fail())
		throw std::runtime_error("Error: Unable to open data.csv file.");
	std::string line;
	std::getline(data, line);
	while (std::getline(data, line))
	{
		size_t pos = line.find(',');
		std::string date = line.substr(0, pos);
		std::string valueStr = line.substr(pos + 1);
		try
		{
			float value = std::atof(valueStr.c_str());
			if (value < 0)
				throw std::runtime_error("Error: Negative value in data.csv: " + valueStr);
			this->_data[date] = value;
		}
		catch (const std::invalid_argument &e)
		{
			throw std::runtime_error("Error: Non-numeric value in data.csv: " + valueStr);
		}
		catch (const std::out_of_range &e)
		{
			throw std::runtime_error("Error: Value out of range in data.csv: " + valueStr);
		}
	}
	data.close();
}

void BitcoinExchange::print_data() const
{
	for (std::map<std::string, float>::const_iterator it = _data.begin(); it != _data.end(); ++it)
	{
		std::cout << it->first << ": " << it->second << std::endl;
	}
}

void BitcoinExchange::process_input_file(const std::string &filename)
{
	std::ifstream inputFile(filename);

	if (inputFile.fail())
		throw std::runtime_error("Error: Unable to open input file.");

	std::string line;
	std::getline(inputFile, line);
	while (std::getline(inputFile, line))
	{
		std::istringstream lineStream(line);
		std::string date;
		std::string valueStr;

		if (!std::getline(lineStream, date, '|'))
		{
			std::cerr << "Error: Invalid line: " << line << std::endl;
			continue;
		}

		if (!is_valid_date(date))
		{
			std::cerr << "Error: Invalid date format: " << date << std::endl;
			continue;
		}

		try
		{
			float value = std::atof(valueStr.c_str());

			if (value < 0)
			{
				std::cerr << "Error: Negative value: " << valueStr << std::endl;
				continue;
			}

			if (value > std::numeric_limits<int>::max())
			{
				std::cerr << "Error: Value out of range: " << valueStr << std::endl;
				continue;
			}
			std::cout << "Date: " << date << ", Value: " << value << std::endl;
		}
		catch (const std::invalid_argument &)
		{
			std::cerr << "Error: Non-numeric value: " << valueStr << std::endl;
		}
		catch (const std::out_of_range &)
		{
			std::cerr << "Error: Value out of range: " << valueStr << std::endl;
		}
	}
	inputFile.close();
}

bool isLeapYear(int year)
{
	return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int daysInMonth(int month, int year)
{
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
	case 2:
		if (isLeapYear(year))
			return 29;
		else
			return 28;
	default:
		std::cerr << "Invalid month" << std::endl;
		return -1;
	}
}

bool BitcoinExchange::is_valid_date(const std::string &date)
{
	int i = 0;
	while (isdigit(date[i]))
		i++;
	if (date.length() < 11 || date[i] != '-')
		return false;
	int j = i;
	while (isdigit(date[j]))
		j++;
	if (date[j] != '-')
		return false;

	std::string year = date.substr(0, i);
	std::string month = date.substr(i + 1, 2);
	std::string day = date.substr(i + 4, 2);

	int y = std::atoi(year.c_str());
	int m = std::atoi(month.c_str());
	int d = std::atoi(day.c_str());
	int days = daysInMonth(m, y);
	if (days < 0 || d > days)
		return false;
	std::cout << "Date: " << y << "-" << m << "-" << d << std::endl;

	return true;
}
