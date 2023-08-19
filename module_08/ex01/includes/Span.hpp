#ifndef SPAN_HPP
# define SPAN_HPP
#include <iostream>

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

		//getter
		unsigned int	getNmax( void ) const;

	private:
		const unsigned int	_n_max;
		int*				_arr;
};

#endif