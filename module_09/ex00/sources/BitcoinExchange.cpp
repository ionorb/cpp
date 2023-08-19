#include "BitcoinExchange.hpp"

//OCCF
BitcoinExchange::BitcoinExchange(std::string input_path) 
{
	this->_input = this->readFile(input_path);
	this->_rawData = this->readFile("data.csv");
	this->_data = this->parseData(this->_rawData);
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
	std::ifstream		t(path.c_str());
	std::stringstream	buffer;
	std::string			err = "Failed to open file: \"" + path + "\"";

	if (!t.is_open())
		throw std::runtime_error(err);
	buffer << t.rdbuf();
	return (buffer.str());
}

std::map<std::string, float>	BitcoinExchange::parseData(std::string rawData) const
{
	typedef std::map<std::string, float> map;
	map								data;
	std::string						key, val;
	std::istringstream				raw(rawData);
	std::string						first;

	getline(raw, key);
	// while (getline(raw, line, ','))
	// {
	// 	std::istringstream	buf(line);
	// 	// getline(raw, first, ',');
	// 	std::cout << line << ", " << first << std::endl;
	// }
	while(std::getline(std::getline(raw, key, ',') >> std::ws, val))
		data[key] = atof(val.c_str());
	for (map::iterator it = data.begin(); it != data.end(); it++)
		std::cout << "key: " << it->first << " val: " << it->second << std::endl;
		
	return (data);
}