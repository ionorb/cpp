#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
#include <map>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
#include <algorithm>

#define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

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
		std::map<std::string, double>	getData() const;

		//setters

	private:
		//attributes
		std::map<std::string, double>	_data;
		std::string						_rawData;
		std::string						_input;

		//methods
		std::string						readFile(std::string path) const;
		std::map<std::string, double>	parseData(std::string rawData) const;
		std::string						removeWhite(std::string str) const;
		void							processInput(std::string input) const;
		std::string						calculateLine(std::string date, std::string value) const;
		void							checkDate(std::string date) const;



};

#endif