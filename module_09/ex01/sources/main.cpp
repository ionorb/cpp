#include "RPN.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: ./RPN [expression]" << std::endl;
		return (1);
	}
	try
	{
		RPN calc(av[1]);

		std::cout << calc.calculate() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	
	return (0);
}