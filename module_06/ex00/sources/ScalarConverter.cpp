/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <myaccount@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 19:12:44 by yoel              #+#    #+#             */
/*   Updated: 2023/05/03 12:28:02 by myaccount        ###   ########.fr       */
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

// void	ScalarConverter::convert(std::string input)
// {
// 	std::istringstream(input) >> ScalarConverter::integer;
// 	std::istringstream(input) >> ScalarConverter::fpoint;
// 	std::istringstream(input) >> ScalarConverter::dpoint;
// 	// std::istringstream(input) >> ScalarConverter::character;
// 	// std::cout << input << std::endl;
// 	std::cout << "char: " << "Non displayable" << std::endl
// 			  << "int: " << ScalarConverter::integer << std::endl
// 			  << "float: " << ScalarConverter::fpoint << "f\n"
// 			  << "double: " << ScalarConverter::dpoint << std::endl;
// }

void ScalarConverter::toChar(std::string input)
{
	std::cout << "\nconvert toChar:\n\n";
	(void)input;
}

void ScalarConverter::toInt(std::string input)
{
	
	(void)input;
	std::cout << "\nconvert toInt:\n\n";
}

void ScalarConverter::toFloat(std::string input)
{
	(void)input;
	std::cout << "\nconvert toFloat:\n\n";
	
}

void ScalarConverter::toDouble(std::string input)
{
	std::cout << "\nconvert toDouble:\n\n";
	
	(void)input;
}

bool ScalarConverter::isInvalidNumber(std::string input)
{	
	if (input == "-inf" || input == "+inf" || input == "nan" \
	|| (std::isalpha(input[0]) && input.size() == 1))
		return (false);
	if (input.size() == 0 || input.find_first_not_of("0123456789.f") != input.npos\
	|| input.find_first_of(".") != input.find_last_of(".") || \
	input.find_first_of("f") != input.find_last_of("f"))
		return (true);
	return (false);
}

int	ScalarConverter::detectType(std::string input)
{
	if (ScalarConverter::isInvalidNumber(input))//input.size() == 0)
		return (UNDEFINED);
	if (std::isalpha(input[0]) && input.size() == 1)
		return (CHAR);
	if (input.find_first_not_of("0123456789") == input.npos)
		return (INT);
	if (input.find_first_of('f') == input.size() - 1 && \
	input.find_first_not_of("0123456789.") == input.size() - 1)
		return (FLOAT);
	if (input.find_first_of(".") != input.npos)
		return (DOUBLE);
	return (UNDEFINED);
}

void ScalarConverter::undefined(std::string input)
{
	std::cout << "\nundefined:\n\n";
	
	(void)input;
}

void	ScalarConverter::convert(std::string input)
{
	typedef	void(*fPointer)(std::string);
	fPointer	conversions[5] = \
	{&ScalarConverter::toChar, &ScalarConverter::toInt, \
	&ScalarConverter::toFloat, &ScalarConverter::toDouble, \
	&ScalarConverter::undefined};
	conversions[ScalarConverter::detectType(input)](input);
	// std::cout << "char: " << ScalarConverter::character << std::endl
	// 		  << "int: " << ScalarConverter::integer << std::endl
	// 		  << "float: " << ScalarConverter::fpoint << "f\n"
	// 		  << "double: " << ScalarConverter::dpoint << std::endl;
}
