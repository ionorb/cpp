#ifndef SPAN_HPP
# define SPAN_HPP
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

class Span
{
	public:
		//OCCF
		Span(unsigned int n);
		~Span();
		Span(const Span& copy);
		Span&	operator = (const Span& copy);

		//member functions
		void			addNumber(int number);
		unsigned int	shortestSpan( void ) const;
		unsigned int	longestSpan( void ) const;

		//getters
		unsigned int		getNmax( void ) const;
		std::vector<int>	getVec( void ) const;

	private:
		const unsigned int	_n_max;
		std::vector<int>	_vec;
};

#endif