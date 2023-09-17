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

int	jacob_num_generate(int j)
{
	int x = 0;

	for (int i = 0; i < j; i++)
		x = (1<<i) - x;
	return x;
}

std::vector< std::vector<int> >	make_paired_sequence(const std::vector<int> &vec)
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
		g_comparison_count++;
		if (pairs[i][0] > pairs[i][1])
			std::iter_swap(pairs[i].begin(), pairs[i].rbegin());
	}
}
void	fill_main_and_pend(std::vector< std::vector<int> > &paired_sequence, std::vector<int> &main_chain, std::vector<int> &pend)
{
	for (size_t i = 0; i < paired_sequence.size(); i++)
	{
		pend.push_back(paired_sequence[i][0]);
		main_chain.push_back(paired_sequence[i][1]);
	}
}

bool	compare_pair(const std::vector<int> &first, const std::vector<int> &second)
{
	g_comparison_count++;
	return (first[1] < second[1]);
}

std::vector< std::vector<int> >	pair_merge_sort(const std::vector< std::vector<int> > &pairs)
{
	if (pairs.size() <= 1)
		return pairs;
	std::vector< std::vector<int> > left(pairs.begin(), pairs.begin() + (pairs.size() / 2));
	std::vector< std::vector<int> > right(pairs.begin() + (pairs.size() / 2), pairs.end());
	std::vector< std::vector<int> > first = pair_merge_sort(left);
	std::vector< std::vector<int> > second = pair_merge_sort(right);
	std::vector< std::vector<int> >	dest(first.size() + second.size());
	std::merge(first.begin(), first.end(), second.begin(), second.end(), dest.begin(), compare_pair);
	return (dest);
}

size_t	binary_insert(std::vector<int> &main_chain, int value, int right)
{
	int left = 0;

	while (left <= right) 
	{
		int mid = left + (right - left) / 2;
		if (main_chain[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
		g_comparison_count++;
	}
	return left; // Return the index where the element should be inserted
}

std::vector<int>	generate_insert_order(size_t size)
{
	std::vector<int>	insert_order;
	int					jacob_num = 0;
	int					prev = 1;

	// for (size_t i = 0; i < size; i++)
	// 	insert_order.push_back(i);
	insert_order.push_back(0);
	for (size_t i = 0; i < size; i++)
	{
		jacob_num = jacob_num_generate(i + 3);
		// insert_order.push_back(jacob_num);
		if (jacob_num >= (int)size)
		{
			for (int i = size - 1; i > prev; i--)
				insert_order.push_back(i);
			break ;
		}
		for (int i = jacob_num; i > prev && insert_order.size() < size; i--)
			insert_order.push_back(i);
		prev = jacob_num;
	}
	std::cout << "order: ";
	for (size_t i = 0; i < insert_order.size(); i++)
		std::cout << insert_order[i] << ", ";
	std::cout << "end\n";
	return insert_order;
}

void	insert_main_chain(std::vector<int> &main_chain, std::vector<int> pend)
{
	int					num_inserted = 0;
	std::vector<int>	insert_order = generate_insert_order(pend.size() - 1);
	
	// main_chain.insert(main_chain.begin(), pend[0]);
	// num_inserted++;
	for (size_t i = 0; i < insert_order.size(); i++)
	{
		int index = insert_order[i];
		int value = pend[index];
		main_chain.insert(main_chain.begin() + binary_insert(main_chain, value, index + num_inserted), value);
		num_inserted++;
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

	//sort each pair in ascending order. e.g. [5, 4] becomes [4, 5]
	sort_pairs(paired_sequence);

	// recursively sort the pairs int order of their second/larger values using merge sort method
	paired_sequence = pair_merge_sort(paired_sequence);

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


	/* Take the second value of each pair (the larger value) and push it to 'main_chain'
	and take the first value of each pair (the smaller value) and push it to 'pend'. */
	fill_main_and_pend(paired_sequence, main_chain, pend);

	std::cout << "main_chain:\t";
	for (size_t i = 0; i < main_chain.size(); i++)
		std::cout << main_chain[i] << ",\t";
	std::cout << "end\n";

	std::cout << "pend:\t\t";
	for (size_t i = 0; i < pend.size(); i++)
		std::cout << pend[i] << ",\t";
	std::cout << "end\n";

	std::cout << "stragler:\t";
	if (is_even)
		std::cout << "FALSE\n";
	else
		std::cout << stragler << std::endl;

	/* Use binary search to insert values from 'pend' into 'main_chain'.
	Values from pend to insert are picked in the order defined by jacobsthal numbers. */
	insert_main_chain(main_chain, pend);
	// for (int i = 0; i < 10; i++)
	// 	std::cout << "JACOB " << i << ": " << jacob_num_generate(i) << std::endl;
	// for (size_t i = 0; i < main_chain.size(); i++)
	// 	std::cout 
	if (!is_even)
		main_chain.insert(main_chain.begin() + binary_insert(main_chain, stragler, main_chain.size() - 1), stragler);
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
