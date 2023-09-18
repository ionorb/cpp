#include "PmergeMe.hpp"

//OCCF
PmergeMe::PmergeMe(char** av, int ac)
{
	proccessInput(av, ac);
}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& copy)
{
	this->_vector = copy.getVector();
	this->_deque = copy.getDeque();
	// this->_num_elems = copy.getNumElems();
}

PmergeMe&	PmergeMe::operator = (const PmergeMe& copy)
{
	if (this != &copy)
	{
		this->_vector = copy.getVector();
		this->_deque = copy.getDeque();
		// this->_num_elems = copy.getNumElems();
	}
	return (*this);
}

std::vector<int>	PmergeMe::getVector() const
{
	return (this->_vector);
}

std::deque<int>	PmergeMe::getDeque() const
{
	return (this->_deque);
}

std::vector<int>	PmergeMe::vectorSort()
{
	return (vecSort(this->_vector));
}

std::deque<int>	PmergeMe::dequeSort()
{
	return (deqSort(this->_deque));
}

void	PmergeMe::proccessInput(char** av, int ac)
{
	int					nbr;

	for (int j = 1; j < ac; j++)
	{
		std::string	num(av[j]);
		if (num.find_first_not_of("0123456789") != num.npos)
			throw std::runtime_error("invalid number in input sequence!");
		if (num.size() > 10)
			throw std::runtime_error("too large number found in sequence!");
		if (atof(num.c_str()) > std::numeric_limits<int>::max())
			throw std::runtime_error("please keep numbers in the range: [ 0 - 2147583647 ]");
		nbr = atoi(num.c_str());
		for (size_t i = 0; i < this->_vector.size(); i++)
		{
			if (this->_vector[i] == nbr)
				throw std::runtime_error("duplicates found in input sequence!");
		}
		this->_vector.push_back(nbr);
		this->_deque.push_back(nbr);
	}
}
