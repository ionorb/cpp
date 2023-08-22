/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <yridgway@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:17:50 by codespace         #+#    #+#             */
/*   Updated: 2023/08/22 15:32:22 by yridgway         ###   ########.fr       */
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
		std::cout << "data content is: \"" << data->content << "\"\n";
		if (data == Serializer::deserialize(Serializer::serialize(data)))
			std::cout << "data is the same :) -> \"" << data->content \
					  << "\"\n";
		else
			std::cout << "data is not the same :/\n";
	}
	else
		std::cout << "wrong number of args!\n";
	delete data;
	return 0;
}