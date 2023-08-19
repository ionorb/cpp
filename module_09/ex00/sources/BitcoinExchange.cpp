#include "BitcoinExchange.hpp"

//OCCF
BitcoinExchange::BitcoinExchange(std::string data_path) 
{
	(void)data_path;
	std::cout << "readfile: " << readFile(data_path) << std::endl;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy)
{
	// for (unsigned int i = 0; i < this->_n_max; i++)
	// 	this->_vec[i] = copy._vec[i];
	(void)copy;
}

BitcoinExchange&	BitcoinExchange::operator = (const BitcoinExchange& copy)
{
	if (this == &copy)
		return (*this);
	return (*this);
}

std::map<std::string, float>	BitcoinExchange::getData() const
{
	return (this->_data);
}

std::string	BitcoinExchange::readFile(std::string path) const
{
	std::ifstream t(path.c_str());
	std::stringstream buffer;

	if (!t.is_open())
		throw std::runtime_error("Failed to open input file");
	buffer << t.rdbuf();
	return (buffer.str());
}