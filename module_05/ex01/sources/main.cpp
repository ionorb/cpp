/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:38:35 by codespace         #+#    #+#             */
/*   Updated: 2023/04/24 19:34:11 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat	urmom("jennifer", 68);
	
	urmom.downgrade();
	try
	{
		std::cout << "try\n";
		std::cout << urmom;
		for (int i = 0; i < 100; i++)
			urmom.downgrade();
	}
	catch(const std::exception& e)
	{
		std::cout << "except\n";
		std::cout << urmom;
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "try\n";
		std::cout << urmom;
		for (int i = 0; i < 300; i++)
			urmom.upgrade();
	}
	catch(const std::exception& e)
	{
		std::cout << "except\n";
		std::cout << urmom;
		std::cerr << e.what() << '\n';
	}
	try
	{
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "hoooo\n";
	return 0;
}