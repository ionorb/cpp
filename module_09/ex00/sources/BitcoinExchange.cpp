#include "BitcoinExchange.hpp"

//OCCF
BitcoinExchange::BitcoinExchange(std::string input_path) 
{
	this->_input = this->readFile(input_path);
	this->_rawData = this->readFile("data.csv");
	this->_data = this->parseData(this->_rawData);
	this->processInput(this->_input);
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

	getline(raw, key);
	while(std::getline(std::getline(raw, key, ',') >> std::ws, val))
		data[key] = atof(val.c_str());
	return (data);
}

std::string	BitcoinExchange::removeWhite(std::string str) const
{
	str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
	return (str);
}

void	BitcoinExchange::processInput(std::string input) const
{
	std::istringstream	in(input);
	std::string			line, date, amount;
	std::string			err = "bad input";

	std::getline(in, date);
	while(std::getline(in, line))
	{
		try
		{
			if (line.find('|') == line.npos)
				throw std::runtime_error(err + " => " + line);
			line = this->removeWhite(line);
			date = line.substr(0, line.find('|'));
			amount = line.substr(line.find('|') + 1);
			std::cout << this->calculateLine(date, amount);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << '\n';
		}
	}
}

std::string	BitcoinExchange::calculateLine(std::string date, std::string amount) const
{
	std::map<std::string, double>	map(this->_data);
	std::string						ret;
	double							value;
	double							num_amount;

	// std::cout << "calc line\n";
	this->checkDate(date);
	num_amount = this->checkAmount(amount);
	if (map.count(date))
		ret = date + " => " + amount + " = " + SSTR(map[date] * num_amount) + "\n";
	else
	{
		map[date] = -69;
		std::map<std::string, double>::iterator it = map.find(date);
		if (it == map.begin())
			value = (++it)->second;
		else
			value = (--it)->second;
		ret = date + " => " + amount + " = " + SSTR(value * num_amount) + "\n";
	}
	return (ret);
}

void	BitcoinExchange::checkDate(std::string date) const
{
	std::string			y, m, d;
	int					year, month, day;
	std::runtime_error	error("invalid date");

	y = date.substr(0, date.find_first_of('-'));
	m = date.substr(date.find_first_of('-') + 1, date.find_last_of('-') - date.find_first_of('-') - 1);
	d = date.substr(date.find_last_of('-') + 1);

	if (y.size() != 4 || m.size() != 2 || d.size() != 2 || \
	y.find_first_not_of("0123456789") != y.npos || \
	m.find_first_not_of("0123456789") != m.npos || \
	d.find_first_not_of("0123456789") != d.npos)
		throw error;

	year = atoi(y.c_str());
	month = atoi(m.c_str());
	day = atoi(d.c_str());

	if( month > 12 || month < 1 ) throw error; //month
	if( day > 31 || day < 1 ) throw error; //day
	if( day == 31 && ( month == 4 || month == 6 || month == 9 || month == 11 ) ) throw error; //30 days in Apr, Jun, Sen, Nov
	if( month == 2 && (day > 29 || (day == 29 && ((year % 100) % 4 != 0))) ) throw error; //Febuary

	// std::string part;
	// std::string dat[3];
	// std::stringstream ss(date);
	// for(int i = 0; std::getline(ss, part, '-') && i < 3; i++)
	// 	dat[i] = part;
	// year = dat[0];
	// month = dat[1];
	// day = dat[2];

	// struct tm tm;
	// if (!strptime(date.c_str(), "%Y-%m-%d", &tm))
		// std::cout << "date: " << date << " isn't valid\n";
	// std::cout << "year: " << tm.tm_year << ", month: " << tm.tm << ", day: " << tm.tm_mday << std::endl;
	// if (!strptime(date2, "%Y-%m-%d", &tm)) std::cout << "date2 isn't valid\n";
	// std::cout << "date: " << date << std::endl;
}

double	BitcoinExchange::checkAmount(std::string amount) const
{
	double	num_amount = atof(amount.c_str());

	if (!amount.empty() && amount[0] == '-')
		throw std::runtime_error("not a positive number");
	if (amount.empty() || amount.find_first_not_of("0123456789.") != amount.npos || std::count(amount.begin(), amount.end(), '.') > 1)
		throw std::runtime_error("invalid number");
	if (num_amount > 1000 || amount.size() > 4)
		throw std::runtime_error("too large a number");
	if (num_amount < 0)
		throw std::runtime_error("not a positive number");
	return (num_amount);
}
