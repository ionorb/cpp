#include "sort_utils.hpp"

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

std::vector<int>	generate_insert_order_vec(size_t size)
{
	std::vector<int>	insert_order;
	int					jacob_num = 0;
	int					prev = 1;

	/*SIMPLE ORDERING*/
	// for (size_t i = 0; i < size; i++)
	// 	insert_order.push_back(i);

	/*JACOBSTHAL ORDERING*/
	insert_order.push_back(0);
	for (size_t j = 0; j < size; j++)
	{
		jacob_num = jacob_num_generate(j + 3);
		if (jacob_num >= (int)size)
		{
			int i = (int)(size);
			while (i > prev)
			{
				insert_order.push_back(i - 1);
				i--;
			}
			break ;
		}
		for (int i = jacob_num; i > prev && insert_order.size() <= size; i--)
			insert_order.push_back(i - 1);
		prev = jacob_num;
	}
	// std::cout << "order: ";
	// for (size_t i = 0; i < insert_order.size(); i++)
	// 	std::cout << insert_order[i] << ", ";
	// std::cout << "end\n";
	return insert_order;
}

void	insert_main_chain(std::vector<int> &main_chain, std::vector<int> pend)
{
	int					num_inserted = 0;
	std::vector<int>	insert_order = generate_insert_order_vec(pend.size());
	
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

std::vector<int> vecSort(std::vector<int> main_chain)
{
	// std::vector<int>				main_chain = this->_vector;
	std::vector<int>				pend;
	std::vector<std::vector<int> >	paired_sequence;

	bool	is_even = true;
	int		stragler;
	
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

	/* Take the second value of each pair (the larger value) and push it to 'main_chain'
	and take the first value of each pair (the smaller value) and push it to 'pend'. */
	fill_main_and_pend(paired_sequence, main_chain, pend);

	/* Use binary search to insert values from 'pend' into 'main_chain'.
	Values from pend to insert are picked in the order defined by jacobsthal numbers. */
	insert_main_chain(main_chain, pend);

	if (!is_even)
		main_chain.insert(main_chain.begin() + binary_insert(main_chain, stragler, main_chain.size() - 1), stragler);
	return main_chain;
}