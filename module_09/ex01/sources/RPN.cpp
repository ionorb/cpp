#include "RPN.hpp"

//OCCF
RPN::RPN(std::string input) 
{
	this->_input = this->removeWhite(input);
}

RPN::~RPN() {}

RPN::RPN(const RPN& copy)
{
	this->_stack = copy.getStack();
}

RPN&	RPN::operator = (const RPN& copy)
{
	if (this != &copy)
		this->_stack = copy.getStack();
	return (*this);
}

//getter
std::stack<int>	RPN::getStack() const
{
	return (this->_stack);
}

std::string	RPN::removeWhite(std::string str) const
{
	str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
	return (str);
}

int	RPN::calculate()
{
	std::string	expr(this->_input);

	std::cout << "calculating...\n";
	std::cout << expr << std::endl;
	if (expr.find_first_not_of("0123456789+-/*"))
		
	for (size_t i = 0; i < expr.size(); i++)
	{
		std::cout << expr[i] << std::endl;
	}
	return (0);
}

