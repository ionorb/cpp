/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:38:35 by codespace         #+#    #+#             */
/*   Updated: 2023/04/24 23:18:51 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	try
	{
		Bureaucrat	high_grade_crat("high crat", 10);
		Bureaucrat	low_grade_crat("low crat", 100);
		Form		hard_form("hard form", 11, 1);
		Form		easy_form("easy form", 101, 1);
		Form		medium_form("medium form", 99, 1);
		Form		extreme_form("extreme form", 9, 1);

		Bureaucrat	broken_crat("boop", -34);
		// Bureaucrat	broken_crat2("boop2", 3434);
		// Form		broken_form("broken", 0, 1);
		// Form		broken_form2("broken2", 151, 1);
		
		// high_grade_crat.signForm(hard_form);
		// high_grade_crat.signForm(easy_form);
		// high_grade_crat.signForm(medium_form);
		// high_grade_crat.signForm(extreme_form);
		// low_grade_crat.signForm(hard_form);
		// low_grade_crat.signForm(easy_form);
		// low_grade_crat.signForm(medium_form);
		// low_grade_crat.signForm(extreme_form);
	}
	catch(const std::exception& e)
	{
		std::cerr << "ERROR: " << e.what() << '\n';
	}
	return 0;
}