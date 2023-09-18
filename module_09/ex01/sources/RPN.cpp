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
	this->_input = copy.getInput();
}

RPN&	RPN::operator = (const RPN& copy)
{
	if (this != &copy)
	{
		this->_stack = copy.getStack();
		this->_input = copy.getInput();
	}
	return (*this);
}

//getters
std::stack<long long>	RPN::getStack() const
{
	return (this->_stack);
}

std::string	RPN::getInput() const
{
	return (this->_input);
}

std::string	RPN::removeWhite(std::string str) const
{
	str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
	return (str);
}

bool isDigit(char c)
{
	if (c >= '0' && c <= '9')
		return true;
	return false;
}

long long	evaluate(char oper, long long first, long long second)
{
	switch (oper)
	{
		case '+':
			return (second + first);
		case '-':
			return (second - first);
		case '/':
			if (first == 0)
				throw std::runtime_error("divide by zero");
			else
				return (second / first);
		case '*':
			return (second * first);
	}
	throw std::runtime_error("invalid operator");
	return (0);
}

int	RPN::calculate()
{
	std::string	expr(this->_input);
	double int_max = std::numeric_limits<int>::max();
	double int_min = std::numeric_limits<int>::min();

	if (expr.find_first_not_of("0123456789+-/*") != expr.npos)
		throw std::runtime_error("invalid char in expression");
	for (size_t i = 0; i < expr.size(); i++)
	{
		if (isDigit(expr[i]))
			this->_stack.push(expr[i] - '0');
		else if (this->_stack.size() >= 2)
		{
			long long first = this->_stack.top();
			if (first > int_max || first < int_min)
				throw std::runtime_error("overflow");
			this->_stack.pop();
			long long second = this->_stack.top();
			if (first > int_max || first < int_min)
				throw std::runtime_error("overflow");
			this->_stack.pop();
			this->_stack.push(evaluate(expr[i], first, second));
		}
		else
			throw std::runtime_error("invalid");
	}
	if (this->_stack.size() > 1)
		throw std::runtime_error("invalid");
	return (this->_stack.top());
}

