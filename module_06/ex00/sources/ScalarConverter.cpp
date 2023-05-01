/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel <yoel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 19:12:44 by yoel              #+#    #+#             */
/*   Updated: 2023/05/01 20:22:50 by yoel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter Default Constrctor\n";
}

// ScalarConverter::~ScalarConverter()
// {
// 	std::cout << "ScalarConverter Default Destructor\n";
// }

// ScalarConverter::ScalarConverter(const ScalarConverter& copy)
// {
// 	std::cout << "ScalarConverter Copy Constructor\n";
// 	(void)copy;
// }

// ScalarConverter&	ScalarConverter::operator = (const ScalarConverter& copy)
// {
// 	std::cout << "ScalarConverter Assignment\n";
// 	(void)copy;
// 	return (*this);
// }

void	ScalarConverter::convert(std::string input)
{
	std::istringstream(input) >> ScalarConverter::integer;
	// std::cout << input << std::endl;
	std::cout << ScalarConverter::integer << std::endl;
}
