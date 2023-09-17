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
		double				list_time = 0, vec_time = 0;
		clock_t				c_start, c_end;
		std::vector<int>	unsorted = merge.getVector(), sorted;
		std::list<int>		sorted_list;
 
		/* Record Vector Sort */
		c_start = std::clock(); //start clock
		sorted = merge.vectorSort();
		c_end = std::clock(); //stop clock
		vec_time = double(c_end - c_start);// / double(CLOCKS_PER_SEC / 1000);

		/* Record List Sort */
		c_start = std::clock(); //start clock
		sorted_list = merge.listSort();
		c_end = std::clock(); //stop clock
		list_time = double(c_end - c_start);// / double(CLOCKS_PER_SEC / 1000);
	
		
		// struct timeval start, end;

		// gettimeofday(&start, NULL); // start timer.
		// // unsync the I/O of C and C++.
		// std::ios_base::sync_with_stdio(false);
		// list = merge.listSort();
		// gettimeofday(&end, NULL); // stop timer.
		// list_time = 1000000 * (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec);

		// gettimeofday(&start, NULL); // start timer.
		// // unsync the I/O of C and C++.
		// std::ios_base::sync_with_stdio(false);
		// sorted = merge.vectorSort();
		// gettimeofday(&end, NULL); // stop timer.
		// vec_time = 1000000 * (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec);
	
		std::cout << "Before: " << showVector(unsorted) << std::endl;
		std::cout << "After: " << showVector(sorted) << std:: endl;
		std::cout << "Time to process a range of " << merge.getNumElems() \
				  << " elements with " << "std::vector : " << std::setprecision(10) << vec_time << "us\n";
		std::cout << "Time to process a range of " << merge.getNumElems() \
				  << " elements with " << "std::list : " << std::setprecision(10) << list_time << "us\n";
		std::cout << "NUMBER OF COMPARISONS: " << g_comparison_count << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}