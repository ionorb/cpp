/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 19:12:44 by yoel              #+#    #+#             */
/*   Updated: 2023/05/10 11:02:03 by codespace        ###   ########.fr       */
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
	if (input == "-inf" || input == "inf" || input == "nan" \
	|| input == "-inff" || input == "inff" || input == "nanf" || \
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
		return (UNDEFINED);
	if (!isdigit(input[0]) && input.size() == 1)
		return (CHAR);
	if (input.find_first_not_of("0123456789-") == input.npos)
		return (INT);
	if ((input.find('f') == input.size() - 1 \
	&& isdigit(input[input.size() - 2])) || \
	(input == "-inff" || input == "inff" || input == "nanf"))
		return (FLOAT);
	if (input.find(".") != input.npos || \
	input == "-inf" || input == "inf" || input == "nan")
		return (DOUBLE);
	return (UNDEFINED);//, std::cout << "\n\nFALLBACK\n\n");
}

void	ScalarConverter::putChar(long double input, bool is_int)
{
	(void)is_int;
	ScalarConverter::character = static_cast<char>(input);
	if (std::isnan(input) || std::isinf(input) || input < 0 || input > 127)
		std::cout << "char: impossible\n";
	else if (ScalarConverter::character <= 32 || ScalarConverter::character == 127)
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: \'" << ScalarConverter::character << "\'\n";
}

void	ScalarConverter::putInt(long double input, bool is_int)
{
	(void)is_int;
	ScalarConverter::integer = static_cast<int>(input);
	if (std::isnan(input) || input > std::numeric_limits<int>::max() \
	|| input < std::numeric_limits<int>::min())
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << ScalarConverter::integer << "\n";
}

void	ScalarConverter::putFloat(long double input, bool is_int)
{
	ScalarConverter::fpoint = static_cast<float>(input);
	if (std::isnan(input))
		ScalarConverter::fpoint = std::numeric_limits<float>::quiet_NaN();
	std::cout << "float: " << ScalarConverter::fpoint;
	if (is_int)
		std::cout << ".0";
	std::cout << "f\n";
}

void	ScalarConverter::putDouble(long double input, bool is_int)
{
	ScalarConverter::dpoint = static_cast<double>(input);
	if (std::isnan(input))
		ScalarConverter::dpoint = std::numeric_limits<double>::quiet_NaN();
	std::cout << "double: " << ScalarConverter::dpoint;
	if (is_int)
		std::cout << ".0";
	std::cout << std::endl;
}

void	ScalarConverter::putValues(long double input, bool is_int)
{
	ScalarConverter::putChar(input, is_int);
	ScalarConverter::putInt(input, is_int);
	ScalarConverter::putFloat(input, is_int);
	ScalarConverter::putDouble(input, is_int);
}

void ScalarConverter::toChar(std::string input)
{
	// std::cout << "\nconvert toChar:\n\n";
	// long double conversion;
	ScalarConverter::character = input[0];
	if (ScalarConverter::character > std::numeric_limits<char>::max() \
	|| ScalarConverter::character < std::numeric_limits<char>::min())
		throw std::overflow_error("Char Overflow!");
	if (ScalarConverter::character <= 32 || ScalarConverter::character == 127)
		throw std::overflow_error("Non Displayable Character!");
	ScalarConverter::putValues(ScalarConverter::character, true);
}

void ScalarConverter::toInt(std::string input)
{
	// std::cout << "\nconvert toInt:\n\n";
	long double conversion;
	std::istringstream(input) >> conversion;
	if (conversion > std::numeric_limits<int>::max() \
	|| conversion < std::numeric_limits<int>::min())
		throw std::overflow_error("Integer Overflow!");
	ScalarConverter::putValues(conversion, true);
}

void ScalarConverter::toFloat(std::string input)
{
	// std::cout << "\nconvert toFloat:\n\n";
	long double conversion;
	input[input.size() - 1] = '\0';
	if (input == "inf")
		conversion = std::numeric_limits<float>::infinity();
	if (input == "-inf")
		conversion = -std::numeric_limits<float>::infinity();
	std::istringstream(input) >> conversion;
	ScalarConverter::putValues(conversion, false);	
}

void ScalarConverter::toDouble(std::string input)
{
	// std::cout << "\nconvert toDouble:\n\n";
	long double conversion;
	std::istringstream(input) >> conversion;
	if (input == "inf")
		conversion = std::numeric_limits<double>::infinity();
	if (input == "-inf")
		conversion = -std::numeric_limits<double>::infinity();
	if (input == "nan")
		conversion = std::numeric_limits<double>::quiet_NaN();
	ScalarConverter::putValues(conversion, false);
}

void ScalarConverter::undefined(std::string input)
{
	(void)input;
	throw std::overflow_error("Invalid Number!");
}

void	ScalarConverter::convert(std::string input)
{
	typedef	void(*fPointer)(std::string);
	fPointer	conversions[5] = \
	{&ScalarConverter::toChar, &ScalarConverter::toInt, \
	&ScalarConverter::toFloat, &ScalarConverter::toDouble, \
	&ScalarConverter::undefined};
	try
	{
		conversions[ScalarConverter::detectType(input)](input);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	// std::cout << "char: " << ScalarConverter::character << std::endl
	// 		  << "int: " << ScalarConverter::integer << std::endl
	// 		  << "float: " << ScalarConverter::fpoint << "f\n"
	// 		  << "double: " << ScalarConverter::dpoint << std::endl;
}
