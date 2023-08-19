/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:02:36 by codespace         #+#    #+#             */
/*   Updated: 2023/08/19 13:05:15 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(int ac, char **av)
{
	unsigned int	n = 10000;
	int				max_int = std::numeric_limits<int>::max();
	int				min_int = std::numeric_limits<int>::min();
	
	try
	{
		if (ac == 2)
			n = atoi(av[1]);
		Span span(n);
		
		srand((unsigned) time(NULL));
		for (unsigned int i = 0; i < n; i++)
			span.addNumber(min_int + (rand() % max_int) * 2);
		// for (unsigned int i = 0; i < span.getVec().size(); i++)
		// {
		// 	std::cout << span.getVec()[i] << std::endl;
		// }
		std::cout << "longest span: " << span.longestSpan() << std::endl;
		std::cout << "shortest span: " << span.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}