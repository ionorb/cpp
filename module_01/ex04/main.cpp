/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel <yoel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 21:02:42 by yoel              #+#    #+#             */
/*   Updated: 2023/04/12 23:03:12 by yoel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>

std::string	ft_replace(std::string content, std::string s1, std::string s2)
{
	long unsigned int	i = 0;

	while ((i = content.find(s1, i)) != std::string::npos)
	{
		content.erase(i, s1.length());
		content.insert(i, s2);
		i += s2.length();
	}
	return (content);
}

int	main(int ac, char **av)
{
	std::ifstream		infile;
	std::ofstream		outfile;
	std::string			content;
	std::stringstream	buffer;

	if (ac == 4)
	{
		std::string		filename = av[1];
		filename.append(".replace");
		if (infile.open(av[1]), !infile.is_open())
			return (std::cerr << "error opening infile\n", 1);
		if (outfile.open(filename.c_str()), !outfile.is_open())
			return (infile.close(), std::cerr << "error creating outfile\n", 1);
		buffer << infile.rdbuf();
		content = buffer.str();
		if (content.find(av[2]) == std::string::npos || !av[2][0])
			return (0);
		outfile << ft_replace(content, av[2], av[3]);
		outfile.close();
	}
	else
		return (std::cerr << "wrong number of arguments!\n", 1);
	return (0);
}