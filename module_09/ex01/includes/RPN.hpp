#ifndef RPN_HPP
# define RPN_HPP
#include <stack>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
#include <algorithm>
#include <ctime>
// #include <strptime>

#define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

class RPN
{
	public:
		//OCCF
		RPN(std::string input);
		~RPN();
		RPN(const RPN& copy);
		RPN&	operator = (const RPN& copy);

		//methods
		int	calculate();

		//getters
		std::stack<long long>	getStack() const;
		std::string		getInput() const;

	private:
		//attributes
		std::stack<long long>	_stack;
		std::string		_input;

		//methods
		std::string		removeWhite(std::string str) const;
};

#endif