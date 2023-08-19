#include <iostream>
#include <cstdlib>
#include <stack>
#include <list>
#include <vector>
#include "MutantStack.hpp"

// int	main(void)
// {
// 	std::stack<int> stk;
// 	MutantStack<int> stook;

// 	srand((unsigned) time(NULL));
// 	for (unsigned int i = 0; i < 100; i++)
// 		stook.push(rand() % 9999999);
// 	for (MutantStack<int>::iterator it = stook.begin(); it != stook.end(); it++)
// 		std::cout << *it << std::endl;
// 	return (0);
// }

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	// std::cout << mstack.top() << std::endl;
	// mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	// std::stack<int> s(mstack);
	return 0;
}
