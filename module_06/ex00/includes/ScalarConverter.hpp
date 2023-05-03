/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <myaccount@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 19:12:47 by yoel              #+#    #+#             */
/*   Updated: 2023/05/03 12:45:53 by myaccount        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
#include <iostream>
#include <string>
#include <sstream>
#define CHAR 0
#define INT 1
#define FLOAT 2
#define DOUBLE 3
#define UNDEFINED 4

class ScalarConverter
{
	private:
		ScalarConverter();
		static bool isInvalidNumber(std::string input);
		static bool containsMultiple(std::string input, std::string set);
		static void	toChar(std::string input);
		static void	toInt(std::string input);
		static void	toFloat(std::string input);
		static void	toDouble(std::string input);
		static void undefined(std::string input);
		static int	detectType(std::string input);
	public:
		static char		character;
		static int		integer;
		static float	fpoint;
		static double	dpoint;
		//OCCF
		// ~ScalarConverter();
		// ScalarConverter(const ScalarConverter& copy);
		// ScalarConverter& operator = (const ScalarConverter& copy);
		//methods
		static void	convert(std::string input);
};

// class Example {
//    public :
//    static int a;
//    static int func(int b) {
//       std::cout << "Static member function called";
//       std::cout << "\nThe value of b is: " << b;
//       return 0;
//    }
// };
// int Example::a = 28;

#endif 