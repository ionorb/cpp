#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
#include <map>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <stdlib.h>

class BitcoinExchange
{
	public:
		//OCCF
		BitcoinExchange(std::string input_path);
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& copy);
		BitcoinExchange&	operator = (const BitcoinExchange& copy);

		//methods

		//getters
		std::map<std::string, float>	getData() const;

		//setters

	private:
		//attributes
		std::map<std::string, float>	_data;
		std::string						_rawData;
		std::string						_input;

		//methods
		std::string						readFile(std::string path) const;
		std::map<std::string, float>	parseData(std::string rawData) const;

};

#endif