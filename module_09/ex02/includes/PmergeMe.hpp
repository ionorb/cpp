#ifndef PMERGEME_HPP
# define PMERGEME_HPP
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
#include <algorithm>
#include <ctime>
#include <vector>
#include <deque>
#include <sys/time.h>
#include <limits>
#include "sort_utils.hpp"

#define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

class PmergeMe
{
	public:
		//OCCF
		PmergeMe(char** av, int ac);
		~PmergeMe();
		PmergeMe(const PmergeMe& copy);
		PmergeMe&	operator = (const PmergeMe& copy);

		//methods
		std::vector<int>	vectorSort();
		std::deque<int>		dequeSort();

		//getters
		std::vector<int>	getVector() const;
		std::deque<int>		getDeque() const;
		// unsigned int		getNumElems() const;

	private:
		//attributes
		std::deque<int>		_deque;
		std::vector<int>	_vector;
		// unsigned int		_num_elems;

		//methods
		void				proccessInput(char** av, int ac);
};

// int					jacob_num_generate(int j);

#endif