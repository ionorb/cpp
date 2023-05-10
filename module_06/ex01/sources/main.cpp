/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:17:50 by codespace         #+#    #+#             */
/*   Updated: 2023/05/10 11:48:12 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int	main(int ac, char **av)
{
	Data	*data = new(Data);

	if (ac == 2)
	{
		data->content = av[1];
		if (data == Serializer::deserialize(Serializer::serialize(data)))
			std::cout << "data is the same :)...\n" << data->content \
					  << std::endl;
		else
			std::cout << "data is not the same :/\n";
	}
	else
		std::cout << "wrong number of args!\n";
	return 0;
}