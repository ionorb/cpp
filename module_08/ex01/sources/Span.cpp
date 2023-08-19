#include "Span.hpp"

//OCCF
Span::Span(unsigned int n) : _n_max(n)
{
	this->_arr = new int[n];
}

Span::~Span()
{
	delete [] this->_arr;
}

Span::Span(const Span& copy) : _n_max(copy.getNmax())
{
	this->_arr = new int[this->_n_max];
	for (unsigned int i = 0; i < this->_n_max; i++)
		this->_arr[i] = copy._arr[i];
}

Span&	Span::operator = (const Span& copy)
{
	if (this == &copy)
		return (*this);
	delete[] this->_arr;
	this->_arr = new int[this->_n_max];
	for (unsigned int i = 0; i < this->_n_max; i++)
		this->_arr[i] = copy._arr[i];
	return (*this);
}

//member functions
void			Span::addNumber(int number)
{
	std::cout << "hello";
	(void)number;
}

unsigned int	Span::shortestSpan( void ) const
{

	std::cout << "hello";
	return 1;
}

unsigned int	Span::longestSpan( void ) const
{
	std::cout << "hello";
	return 1;

}

//getter
unsigned int	Span::getNmax( void ) const
{
	return (this->_n_max);
}
