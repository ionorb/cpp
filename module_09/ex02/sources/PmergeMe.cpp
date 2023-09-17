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

// int	jacob_num(int i, int j)
// {
// 	int	jacob = 0;
// 	jacob = (1<<i) - j;
// 	return (jacob);
// }

int	jacob_num(int j)
{
	int x = 0;

	for (int i = 0; i < j; i++)
		x = (1<<i) - x;
	return x;
}

std::vector<int>	PmergeMe::vectorSort()
{
	std::vector<int> vec;
	// int prev = 1;
	for (int i = 0; i < 10; i++)
	{
		std::cout << "JACOB " << i << ": " << jacob_num(i) << std::endl;
	// 	prev = jacob_num(i, prev);
	// 	std::cerr << "JACOB " << i << ": " << prev << std::endl;
	}
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
		if (num.find_first_not_of("0123456789") != num.npos)
			throw std::runtime_error("invalid number in input sequence!");
		if (num.size() > 10)
			throw std::runtime_error("too large number found in sequence!");
		if (atof(num.c_str()) > std::numeric_limits<int>::max())
			throw std::runtime_error("please keep numbers in the range: [ 0 - 2147583647 ]");
		this->_vector.push_back(atoi(num.c_str()));
		this->_list.push_back(atoi(num.c_str()));
	}
}
