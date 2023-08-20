#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: ./PmergeMe [sequence]" << std::endl;
		return (1);
	}
	try
	{
		PmergeMe	merge(av[1]);

		// std::cout << "result: " << calc.calculate() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}