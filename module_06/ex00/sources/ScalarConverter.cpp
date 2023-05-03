/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <myaccount@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 19:12:44 by yoel              #+#    #+#             */
/*   Updated: 2023/05/03 13:34:00 by myaccount        ###   ########.fr       */
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

bool ScalarConverter::containsMultiple(std::string input, std::string set)
{
	for (size_t i = 0; i < set.size(); i++)
	{
		if (input.find_first_of(set[i]) != input.find_last_of(set[i]))
			return true;
	}
	return false;
}

bool ScalarConverter::isInvalidNumber(std::string input)
{	
	if (input == "-inf" || input == "+inf" || input == "nan" \
	|| input == "-inff" || input == "+inff" || input == "nanf" || \
	(!isdigit(input[0]) && input.size() == 1))
		return (false);
	if (input.size() == 0 || input.find_first_not_of("0123456789.-f") != input.npos \
	|| containsMultiple(input, ".-f") || (input.find("-") != 0 \
	&& input.find("-") != input.npos))
		return (true);
	if ((input.find("f") != input.npos && \
	!isdigit(input[input.find("f") - 1])) || \
	(input.find("f") != input.size() - 1 \
	&& input.find("f") != input.npos))
		return (true);
	if (input.find(".") != input.npos \
	&& input.find(".") == input.size() - 1)
		return (true);
	return (false);
}

int	ScalarConverter::detectType(std::string input)
{
	if (ScalarConverter::isInvalidNumber(input))//input.size() == 0)
		return (std::cout << "invalidnum\n", UNDEFINED);
	if (isalpha(input[0]) && input.size() == 1)
		return (CHAR);
	if (input.find_first_not_of("0123456789-") == input.npos)
		return (INT);
	if ((input.find('f') == input.size() - 1 \
	&& isdigit(input[input.size() - 2])) || \
	(input == "-inff" || input == "+inff" || input == "nanf"))
		return (FLOAT);
	if (input.find(".") != input.npos || \
	input == "-inf" || input == "+inf" || input == "nan")
		return (DOUBLE);
	return (std::cout << "\n\nFALLBACK\n\n", UNDEFINED);
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
