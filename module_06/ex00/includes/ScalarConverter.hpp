/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel <yoel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 19:12:47 by yoel              #+#    #+#             */
/*   Updated: 2023/05/01 20:22:15 by yoel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
#include <iostream>
#include <string>
#include <sstream>

class ScalarConverter
{
	private:
		ScalarConverter();
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