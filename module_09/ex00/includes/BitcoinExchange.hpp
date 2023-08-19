#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
#include <map>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

class BitcoinExchange
{
	public:
		//OCCF
		BitcoinExchange(std::string data_path);
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& copy);
		BitcoinExchange&	operator = (const BitcoinExchange& copy);

		//member functions

		//getters
		std::map<std::string, float>	getData() const;

		//setters

	private:
		std::map<std::string, float> _data;

		std::string	readFile(std::string path) const;
};

#endif