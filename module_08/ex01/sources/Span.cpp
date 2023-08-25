#include "Span.hpp"

//OCCF
Span::Span() : _n_max(0) {}

Span::Span(unsigned int n) : _n_max(n) {}

Span::~Span() {}

Span::Span(const Span& copy) : _n_max(copy.getNmax()), _vec(copy.getVec())
{
	// for (unsigned int i = 0; i < this->_n_max; i++)
	// 	this->_vec[i] = copy._vec[i];
}

Span&	Span::operator = (const Span& copy)
{
	if (this == &copy)
		return (*this);
	this->_vec = copy.getVec();
	// for (unsigned int i = 0; i < this->_n_max; i++)
	// 	this->_vec[i] = copy._vec[i];
	return (*this);
}

//member functions
void	Span::addNumber(int number)
{
	if (this->_vec.size() >= this->_n_max)
		throw std::out_of_range("Maximum number of items reached");
	this->_vec.push_back(number);
}

unsigned int	Span::shortestSpan( void ) const
{
	std::vector<int>	vec(this->_vec);
	long				minspan = std::numeric_limits<long>::max();

	if (vec.size() < 2)
		throw std::out_of_range("Not enough items to calculate span");
	std::sort(vec.begin(), vec.end());
	for (unsigned int i = 0; i < vec.size() - 1; i++)
	{
		if (vec[i + 1] - vec[i] < minspan)
			minspan = vec[i + 1] - vec[i];
	}
	return minspan;
}

unsigned int	Span::longestSpan( void ) const
{
	std::vector<int>	vec(this->_vec);

	if (vec.size() < 2)
		throw std::out_of_range("Not enough items to calculate span");
	std::sort(vec.begin(), vec.end());
	return (*vec.rbegin() - *vec.begin());

}

//getters
unsigned int	Span::getNmax( void ) const
{
	return (this->_n_max);
}

std::vector<int>	Span::getVec( void ) const
{
	return (this->_vec);
}
