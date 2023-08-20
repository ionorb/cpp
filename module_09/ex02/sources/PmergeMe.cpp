#include "PmergeMe.hpp"

//OCCF
PmergeMe::PmergeMe(std::string input) 
{
	this->_input = input;
	proccessInput();
}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& copy)
{
	this->_vector = copy.getVector();
	this->_list = copy.getList();
	this->_input = copy.getInput();
	this->_num_elems = copy.getNumElems();
}

PmergeMe&	PmergeMe::operator = (const PmergeMe& copy)
{
	if (this != &copy)
	{
		this->_vector = copy.getVector();
		this->_list = copy.getList();
		this->_input = copy.getInput();
		this->_num_elems = copy.getNumElems();
	}
	return (*this);
}

std::vector<int>	PmergeMe::getVector() const
{
	return (this->_vector);
}

std::list<int>	PmergeMe::getList() const
{
	return (this->_list);
}
std::string	PmergeMe::getInput() const
{
	return (this->_input);
}

unsigned int	PmergeMe::getNumElems() const
{
	return (this->_num_elems);
}

std::vector<int>	PmergeMe::vectorSort()
{
	std::vector<int> vec;
	return vec;
}

std::list<int>	PmergeMe::listSort()
{
	std::list<int> lst;
	return lst;
}

void	PmergeMe::proccessInput()
{
	std::stringstream	ss(this->_input);
	std::string			num;
	std::vector<int>	vec;

	for(int i = 0; std::getline(ss, num, ' '); i++)
	{
		this->_vector.push_back(atoi(num.c_str()));
		this->_list.push_back(atoi(num.c_str()));
	}
}
