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
	this->_list = copy.getList();
	this->_num_elems = copy.getNumElems();
}

PmergeMe&	PmergeMe::operator = (const PmergeMe& copy)
{
	if (this != &copy)
	{
		this->_vector = copy.getVector();
		this->_list = copy.getList();
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

std::vector< std::vector<int> >	make_paired_sequence(std::vector<int> vec)
{
	std::vector< std::vector<int> >	paired_sequence;
 
	// split vector into pairs and add them to a list of pairs: 'paired_sequence'
	for (size_t i = 0; i < vec.size(); i+=0)
	{
		std::vector<int> pair;
		pair.push_back(vec[i++]);
		pair.push_back(vec[i++]);
		paired_sequence.push_back(pair);
	}
	return paired_sequence;
}

void	sort_pairs(std::vector< std::vector<int> > &pairs)
{
	for (size_t i = 0; i < pairs.size(); i++)
	{
		if (pairs[i][0] > pairs[i][1])
			std::iter_swap(pairs[i].begin(), pairs[i].rbegin());
	}
}
void	fill_main_and_pend(std::vector< std::vector<int> > paired_sequence, std::vector<int> &main_chain, std::vector<int> &pend)
{
	for (size_t i = 0; i < paired_sequence.size(); i++)
	{
		pend.push_back(paired_sequence[i][0]);
		main_chain.push_back(paired_sequence[i][1]);
	}
}

std::vector<int>	PmergeMe::vectorSort()
{
	std::vector<int>				main_chain = this->_vector;
	std::vector<int>				pend;
	std::vector<std::vector<int> >	paired_sequence;
	
	bool	is_even = true;
	int		stragler;
	(void)is_even;
	(void)stragler;
	
	// check if sequence is odd and add stragler if so
	if (main_chain.size() % 2)
	{
		is_even = false;
		stragler = *main_chain.rbegin();
		main_chain.pop_back();
	}

	//group all elements into vectors with two elements to make a vector of vectors with two ints
	paired_sequence = make_paired_sequence(main_chain);

	main_chain.clear(); // clear main_chain for later use

	// // printing paired sequence
	// std::cout << "Paired Sequence:\n";
	// for (size_t i = 0; i < paired_sequence.size(); i++)
	// 	std::cout << "[" << paired_sequence[i][0] << ", " << paired_sequence[i][1] << "], ";
	// std::cout << "stragler: ";
	// if (is_even)
	// 	std::cout << "FALSE\n";
	// else
	// 	std::cout << stragler << std::endl;
	// std::cout << std::endl;

	//sort each pair in ascending order. e.g. [5, 4] becomes [4, 5]
	sort_pairs(paired_sequence);

	// printing paired sequence
	std::cout << "Paired Sequence:\n";
	for (size_t i = 0; i < paired_sequence.size(); i++)
		std::cout << "[" << paired_sequence[i][0] << ", " << paired_sequence[i][1] << "], ";
	std::cout << "stragler: ";
	if (is_even)
		std::cout << "FALSE\n";
	else
		std::cout << stragler << std::endl;
	std::cout << std::endl;

	/* Take the second value of each pair (the larger value) and push it to 'main_chain'
	 and take the first value of each pair (the smaller value) and push it to 'pend'. */
	fill_main_and_pend(paired_sequence, main_chain, pend);

	// for (int i = 0; i < 10; i++)
	// 	std::cout << "JACOB " << i << ": " << jacob_num(i) << std::endl;
	return main_chain;
}

std::list<int>	PmergeMe::listSort()
{
	std::list<int> lst;
	return lst;
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
		this->_list.push_back(nbr);
	}
}
