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
	std::vector<int>				vec = this->_vector;
	std::vector<std::vector<int> >	paired_sequence;
	
	bool	is_even = true;
	int		stragler;
	
	if (vec.size() % 2)
	{
		is_even = false;
		stragler = *vec.rbegin();
		vec.pop_back();
	}
	for (size_t i = 0; i < vec.size(); i+=0)
	{
		std::vector<int> pair;
		pair.push_back(vec[i++]);
		pair.push_back(vec[i++]);
		paired_sequence.push_back(pair);
	}
	std::cout << "Paired Sequence:\n";
	for (size_t i = 0; i < paired_sequence.size(); i++)
	{
		std::cout << "[" << paired_sequence[i][0] << ", " << paired_sequence[i][1] << "], ";
	}
	std::cout << "stragler: ";
	if (is_even)
		std::cout << "FALSE\n";
	else
		std::cout << stragler << std::endl;
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
	int					nbr;
	// std::vector<int>	vec;

	while (std::getline(ss, num, ' '))
	{
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
		this->_list.push_back(nbr);
	}
}
