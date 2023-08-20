#include "PmergeMe.hpp"

//OCCF
PmergeMe::PmergeMe(std::string input) 
{
	this->_input = input;
}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& copy)
{
	this->_vector = copy.getVector();
	this->_list = copy.getList();
	this->_input = copy.getInput();
}

PmergeMe&	PmergeMe::operator = (const PmergeMe& copy)
{
	if (this != &copy)
	{
		this->_vector = copy.getVector();
		this->_list = copy.getList();
		this->_input = copy.getInput();
	}
	return (*this);
}

std::vector<int>	PmergeMe::getVector() const
{
	return (this->_vector);
}

std::list<int>		PmergeMe::getList() const
{
	return (this->_list);
}
std::string		PmergeMe::getInput() const
{
	return (this->_input);
}
