#ifndef SORT_UTILS_H
# define SORT_UTILS_H
#include <algorithm>
#include <ctime>
#include <vector>
#include <deque>

extern int g_comparison_count;

std::vector<int>	vecSort(std::vector<int> main_chain);
std::deque<int>		deqSort(std::deque<int> main_chain);
int	jacob_num_generate(int j);
#endif