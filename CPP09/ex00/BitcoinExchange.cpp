#include "BitcoinExchange.hpp"
#include <sstream>
#include <string>

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
		float value = std::atof(valueStr.c_str());
		this->_data[date] = value;
	}
	data.close();
}

void BitcoinExchange::print_data() const
{
	for (std::map<std::string, double>::const_iterator it = _data.begin(); it != _data.end(); ++it)
	{
		std::cout << it->first << ": " << it->second << std::endl;
	}
}
bool isValidDouble(std::string str, double *value)
{
	char *end; // TODO
	for (size_t i = 0; !isdigit(str[i]); i++)
	{
		if (!(str[i] == '-' || str[i] == '+' || str[i] == '.'))
			return false;
	}
	*value = std::strtod(str.c_str(), &end);

	if (str == end)
		return false;
	while (*end != '\0')
	{
		if (!std::isspace(*end))
			return false;
		++end;
	}
	return true;
}

void BitcoinExchange::process_input_file(const std::string &filename)
{
	std::ifstream inputFile(filename);
	std::string date;
	std::string valueStr;
	double value = 0;

	if (inputFile.fail())
		throw std::runtime_error("Error: Unable to open input file.");
	std::string line;
	std::getline(inputFile, line);
	if (line != "date | value")
		throw std::runtime_error("Error: Invalid Header (date | value).");
	while (std::getline(inputFile, line))
	{
		std::istringstream lineStream(line);
		if (!std::getline(lineStream, date, '|') || date.back() != ' ')
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		if (!is_valid_date(date))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		if (!std::getline(lineStream, valueStr) || valueStr.size() < 2 || valueStr[0] != ' ')
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		valueStr.erase(valueStr.begin());
		if (!isValidDouble((valueStr), &value))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		if (value < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		if (value > 1000.0)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}
		date.erase(std::remove(date.begin(), date.end(), ' '), date.end());

		std::map<std::string, double>::iterator it = _data.lower_bound(date);
		if (it == _data.end())
			std::cout << date << " => " << value << " = " << (--it)->second * value << std::endl;
		else if (it != _data.end())
			std::cout << date << " => " << value << " = " << it->second * value << std::endl;
		else
			std::cout << date << " => " << value << " = No exchange rate for this date" << std::endl;
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
		return -1;
	}
}

bool BitcoinExchange::is_valid_date(std::string &date)
{
	double y = 0;
	double m = 0;
	double d = 0;
	if (!date.empty() && date.back() == ' ')
		date.erase(date.size() - 1);
	int count = 0;
	for (size_t i = 0; i < date.size(); i++)
	{
		if (date[i] == '-')
			count++;
		if (!isdigit(date[i]) && date[i] != '-')
			if (!isdigit(date[i]) && date[i] != '-')
				return false;
	}
	if (count > 2)
		return false;
	std::istringstream dateStream(date);
	std::string tmp;

	std::getline(dateStream, tmp, '-');
	if (!isValidDouble(tmp, &y) || strchr(tmp.c_str(), '.'))
		return false;
	std::getline(dateStream, tmp, '-');
	if (!isValidDouble(tmp, &m) || strchr(tmp.c_str(), '.'))
		return false;
	std::getline(dateStream, tmp, '-');
	if (!isValidDouble(tmp, &d) || strchr(tmp.c_str(), '.'))
		return false;

	int days = daysInMonth(m, y);
	if (days < 0 || d > days)
		return false;
	return true;
}
