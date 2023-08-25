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
#include <list>
#include <sys/time.h>

#define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

class PmergeMe
{
	public:
		//OCCF
		PmergeMe(std::string input);
		~PmergeMe();
		PmergeMe(const PmergeMe& copy);
		PmergeMe&	operator = (const PmergeMe& copy);

		//methods
		std::vector<int>	vectorSort();
		std::list<int>		listSort();

		//getters
		std::vector<int>	getVector() const;
		std::list<int>		getList() const;
		std::string			getInput() const;
		unsigned int		getNumElems() const;

	private:
		//attributes
		std::string			_input;
		std::list<int>		_list;
		std::vector<int>	_vector;
		unsigned int		_num_elems;

		//methods
		void				proccessInput();
};

#endif