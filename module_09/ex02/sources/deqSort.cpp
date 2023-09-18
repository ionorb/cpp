#include "sort_utils.hpp"

int	jacob_num_generate(int j)
{
	int x = 0;

	for (int i = 0; i < j; i++)
		x = (1<<i) - x;
	return x;
}

std::deque< std::deque<int> >	make_paired_sequence(const std::deque<int> &deq)
{
	std::deque< std::deque<int> >	paired_sequence;
 
	// split deque into pairs and add them to a list of pairs: 'paired_sequence'
	for (size_t i = 0; i < deq.size(); i+=0)
	{
		std::deque<int> pair;
		pair.push_back(deq[i++]);
		pair.push_back(deq[i++]);
		paired_sequence.push_back(pair);
	}
	return paired_sequence;
}

void	sort_pairs(std::deque< std::deque<int> > &pairs)
{
	for (size_t i = 0; i < pairs.size(); i++)
	{
		deq_comparison_count++;
		if (pairs[i][0] > pairs[i][1])
			std::iter_swap(pairs[i].begin(), pairs[i].rbegin());
	}
}
void	fill_main_and_pend(std::deque< std::deque<int> > &paired_sequence, std::deque<int> &main_chain, std::deque<int> &pend)
{
	for (size_t i = 0; i < paired_sequence.size(); i++)
	{
		pend.push_back(paired_sequence[i][0]);
		main_chain.push_back(paired_sequence[i][1]);
	}
}

bool	compare_pair(const std::deque<int> &first, const std::deque<int> &second)
{
	deq_comparison_count++;
	return (first[1] < second[1]);
}

std::deque< std::deque<int> >	pair_merge_sort(const std::deque< std::deque<int> > &pairs)
{
	if (pairs.size() <= 1)
		return pairs;
	std::deque< std::deque<int> > left(pairs.begin(), pairs.begin() + (pairs.size() / 2));
	std::deque< std::deque<int> > right(pairs.begin() + (pairs.size() / 2), pairs.end());
	std::deque< std::deque<int> > first = pair_merge_sort(left);
	std::deque< std::deque<int> > second = pair_merge_sort(right);
	std::deque< std::deque<int> >	dest(first.size() + second.size());
	std::merge(first.begin(), first.end(), second.begin(), second.end(), dest.begin(), compare_pair);
	return (dest);
}

size_t	binary_insert(std::deque<int> &main_chain, int value, int right)
{
	int left = 0;

	while (left <= right) 
	{
		int mid = left + (right - left) / 2;
		if (main_chain[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
		deq_comparison_count++;
	}
	return left; // Return the index where the element should be inserted
}

std::deque<int>	generate_insert_order_deq(size_t size)
{
	std::deque<int>		insert_order;
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

void	insert_main_chain(std::deque<int> &main_chain, std::deque<int> pend)
{
	int					num_inserted = 0;
	std::deque<int>	insert_order = generate_insert_order_deq(pend.size());
	
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

std::deque<int> deqSort(std::deque<int> main_chain)
{
	// std::deque<int>				main_chain = this->_deque;
	std::deque<int>				pend;
	std::deque<std::deque<int> >	paired_sequence;

	bool	is_even = true;
	int		stragler;
	
	// check if sequence is odd and add stragler if so
	if (main_chain.size() % 2)
	{
		is_even = false;
		stragler = *main_chain.rbegin();
		main_chain.pop_back();
	}

	//group all elements into deques with two elements to make a deque of deques with two ints
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

	// // printing main chain and pend deques
	// std::cout << "main_chain:\t";
	// for (size_t i = 0; i < main_chain.size(); i++)
	// 	std::cout << main_chain[i] << ",\t";
	// std::cout << "end\n";

	// std::cout << "pend:\t\t";
	// for (size_t i = 0; i < pend.size(); i++)
	// 	std::cout << pend[i] << ",\t";
	// std::cout << "end\n";

	// std::cout << "stragler:\t";
	// if (is_even)
	// 	std::cout << "FALSE\n";
	// else
	// 	std::cout << stragler << std::endl;

	/* Use binary search to insert values from 'pend' into 'main_chain'.
	Values from pend to insert are picked in the order defined by jacobsthal numbers. */
	insert_main_chain(main_chain, pend);

	if (!is_even)
		main_chain.insert(main_chain.begin() + binary_insert(main_chain, stragler, main_chain.size() - 1), stragler);
	return main_chain;
}


// std::deque<int>		deqSort(std::deque<int> main_chain)
// {
// 	(void)main_chain;
// 	std::deque<int> deq;
// 	return deq;
// }