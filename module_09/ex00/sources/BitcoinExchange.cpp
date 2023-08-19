#include "BitcoinExchange.hpp"

//OCCF
BitcoinExchange::BitcoinExchange(std::string input_path) 
{
	this->_input = this->readFile(input_path);
	this->_rawData = this->readFile("data.csv");
	this->_data = this->parseData(this->_rawData);
	this->processInput(this->_input);
}

std::string	BitcoinExchange::calculateLine(std::string date, std::string value) const
{
	std::map<std::string, double>	map(this->_data);
	std::string						ret;
	double							val;

	// std::cout << "calc line\n";
	this->checkDate(date);
	if (map.count(date))
		ret = date + " => " + value + " = " + SSTR(map[date] * atof(value.c_str())) + "\n";
	else
	{
		map[date] = -69;
		std::map<std::string, double>::iterator it = map.find(date);
		if (it == map.begin())
			val = (++it)->second;
		else
			val = (--it)->second;
		// std::cout << "MAP: " << map[date] << " VAL: " << val << std::endl;
		ret = date + " => " + value + " = " + SSTR(val * atof(value.c_str())) + "\n";
	}
	return (ret);
}

void	BitcoinExchange::checkDate(std::string date) const
{
	(void)date;
}

void	BitcoinExchange::processInput(std::string input) const
{
	std::istringstream	in(input);
	std::string			line, date, value;

	std::getline(in, date);
	while(std::getline(in, line))
	{
		try
		{
			if (line.find('|') == line.npos)
				throw std::runtime_error("bad input");
			line = this->removeWhite(line);
			date = line.substr(0, line.find('|'));
			value = line.substr(line.find('|') + 1);
			// std::cout << "\'" << date << "\' | \'" << value << "\'" << std::endl;
			std::cout << this->calculateLine(date, value);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << '\n';
		}
	}
	// std::cout << "map: " << this->_data["2022-03-10"] << std::endl;
}

std::string	BitcoinExchange::removeWhite(std::string str) const
{
	std::string	nows = str;
	nows.erase(remove_if(nows.begin(), nows.end(), isspace), nows.end());
	return (nows);
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

std::map<std::string, double>	BitcoinExchange::getData() const
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

std::map<std::string, double>	BitcoinExchange::parseData(std::string rawData) const
{
	typedef std::map<std::string, double> map;
	map								data;
	std::string						key, val;
	std::istringstream				raw(rawData);
	std::string						first;

	// while (getline(raw, line, ','))
	// {
	// 	std::istringstream	buf(line);
	// 	// getline(raw, first, ',');
	// 	std::cout << line << ", " << first << std::endl;
	// }
	getline(raw, key);
	while(std::getline(std::getline(raw, key, ',') >> std::ws, val))
		data[key] = atof(val.c_str());
	// for (map::iterator it = data.begin(); it != data.end(); it++)
	// 	std::cout << it->first << "," << std::setprecision(10) << it->second << std::endl;
		
	return (data);
}