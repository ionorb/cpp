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

#define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

extern int g_comparison_count;

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

std::vector<int>	vecSort(std::vector<int> main_chain);
std::deque<int>		deqSort(std::deque<int> main_chain);

#endif