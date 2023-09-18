#include "PmergeMe.hpp"

int deq_comparison_count = 0;
int vec_comparison_count = 0;

std::string	showVector(std::vector<int> vec)
{
	std::string	ret;

	for (size_t i = 0; i < vec.size(); i++)
		ret = ret + SSTR(vec[i]) + " ";
	return (ret);
}

int	main(int ac, char **av)
{
	if (ac < 3)
	{
		std::cerr << "Usage: ./PmergeMe [sequence]" << std::endl;
		std::cerr << "please each number as a seperate argument in the sequence.\n";
		std::cerr << "at least 2 numbers must be given.\n";
		return (1);
	}
	try
	{
		PmergeMe			merge(av, ac);
		double				deque_time = 0, vec_time = 0;
		clock_t				c_start, c_end;
		std::vector<int>	unsorted = merge.getVector(), sorted;
		std::deque<int>		sorted_deque;
 
		/* Record Vector Sort */
		c_start = std::clock(); //start clock
		sorted = merge.vectorSort();
		c_end = std::clock(); //stop clock
		vec_time = static_cast<double>(c_end - c_start) / CLOCKS_PER_SEC * 1000;

		/* Record deque Sort */
		c_start = std::clock(); //start clock
		sorted_deque = merge.dequeSort();
		c_end = std::clock(); //stop clock
		deque_time = static_cast<double>(c_end - c_start) / CLOCKS_PER_SEC * 1000;
	
		std::cout << "Before: " << showVector(unsorted) << std::endl;
		std::cout << "After: " << showVector(sorted) << std:: endl;
		std::cout << "Time to process a sequence of " << ac - 1 \
				  << " elements with " << "std::vector :\t" << std::setprecision(10) << vec_time << "ms\n";
		std::cout << "Time to process a sequence of " << ac - 1\
				  << " elements with " << "std::deque :\t" << std::setprecision(10) << deque_time << "ms\n";
		std::cout << "NUMBER OF VEC COMPARISONS: " << vec_comparison_count << std::endl;
		std::cout << "NUMBER OF DEC COMPARISONS: " << deq_comparison_count << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}