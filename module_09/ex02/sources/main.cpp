#include "PmergeMe.hpp"

int g_comparison_count = 0;

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
		vec_time = static_cast<double>(c_end - c_start) / CLOCKS_PER_SEC * 1000000;

		/* Record deque Sort */
		c_start = std::clock(); //start clock
		sorted_deque = merge.dequeSort();
		c_end = std::clock(); //stop clock
		deque_time = static_cast<double>(c_end - c_start) / CLOCKS_PER_SEC * 1000000;
	
		
		// struct timeval start, end;

		// gettimeofday(&start, NULL); // start timer.
		// // unsync the I/O of C and C++.
		// std::ios_base::sync_with_stdio(false);
		// deque = merge.dequeSort();
		// gettimeofday(&end, NULL); // stop timer.
		// deque_time = 1000000 * (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec);

		// gettimeofday(&start, NULL); // start timer.
		// // unsync the I/O of C and C++.
		// std::ios_base::sync_with_stdio(false);
		// sorted = merge.vectorSort();
		// gettimeofday(&end, NULL); // stop timer.
		// vec_time = 1000000 * (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec);
	
		std::cout << "Before: " << showVector(unsorted) << std::endl;
		std::cout << "After: " << showVector(sorted) << std:: endl;
		std::cout << "Time to process a sequence of " << ac \
				  << " elements with " << "std::vector : " << std::setprecision(10) << vec_time << "us\n";
		std::cout << "Time to process a sequence of " << ac \
				  << " elements with " << "std::deque : " << std::setprecision(10) << deque_time << "us\n";
		// std::cout << "NUMBER OF COMPARISONS: " << g_comparison_count << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}