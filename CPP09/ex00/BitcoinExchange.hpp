#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>

class BitcoinExchange
{
private:
public:
	std::map<std::string, double> _data;
	BitcoinExchange(void);
	BitcoinExchange(BitcoinExchange const &copy);
	~BitcoinExchange(void);
	BitcoinExchange const &operator=(BitcoinExchange const &rhs);
	void store_data(void);
	void print_data() const;
	bool is_valid_date(std::string &date);
	void process_input_file(const std::string &filename);
};

#endif