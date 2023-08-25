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
		Span();
		Span(unsigned int n);
		~Span();
		Span(const Span& copy);
		Span&	operator = (const Span& copy);

		//member functions
		void			addNumber(int number);

		template <class InputIterator>
		void addRange(InputIterator first, InputIterator last);

		unsigned int	shortestSpan( void ) const;
		unsigned int	longestSpan( void ) const;

		//getters
		unsigned int		getNmax( void ) const;
		std::vector<int>	getVec( void ) const;

	private:
		const unsigned int	_n_max;
		std::vector<int>	_vec;
};

template <class InputIterator> 
void Span::addRange(InputIterator first, InputIterator last)
{
	this->_vec.insert(this->_vec.end(), first, last);
	if (this->_vec.size() > this->_n_max)
		throw std::out_of_range("Maximum number of items reached");
}

#endif