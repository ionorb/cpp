/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:02:36 by codespace         #+#    #+#             */
/*   Updated: 2023/08/25 16:17:58 by codespace        ###   ########.fr       */
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
		std::vector<int> vec;

		srand((unsigned) time(NULL));
		// for (unsigned int i = 0; i < n; i++)
		// 	span.addNumber(min_int + (rand() % max_int) * 2);
		for (unsigned int i = 0; i < n; i++)
			vec.push_back((min_int + (rand() % max_int) * 2));
		span.addRange(vec.begin(), vec.end());
		std::cout << "longest span: " << span.longestSpan() << std::endl;
		std::cout << "shortest span: " << span.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Span span(n);
		int myarray [] = { 6, 3, 17, 9, 11 };
		
		srand((unsigned) time(NULL));
		span.addRange(myarray, myarray + 5);
		std::cout << "longest span: " << span.longestSpan() << std::endl;
		std::cout << "shortest span: " << span.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}