/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <yridgway@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:38:35 by codespace         #+#    #+#             */
/*   Updated: 2023/04/27 23:20:51 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"


int	main()
{
	try
	{
		std::cout << "\n-------CONSTRUCTION-------\n";
		Bureaucrat				bureaury("bureaury", 100);
		AForm*	signed_shrubbery;
		AForm*	unsigned_shrubbery;
		AForm*	robotomy;
		AForm*	pardon;
		Intern					terny;
		
		signed_shrubbery = (terny.makeForm("shrubbery creation", "bobby"));
		unsigned_shrubbery = (terny.makeForm("shrubbery creation", "bobby"));
		robotomy = (terny.makeForm("shrubbery creation", "bobby"));
		pardon = (terny.makeForm("shrubbery creation", "bobby"));
		std::cout << "--------------------------\n";

		std::cout << "\n-------BUREAUCRATS--------\n";
		std::cout << "\nBUREAUCRAT THAT CAN EXEC:\n";
		std::cout << bureaury;
		std::cout << "--------------------------\n";

		std::cout << "\n----------SIGNING---------\n";
		bureaury.signForm(*signed_shrubbery);
		bureaury.signForm(*robotomy);
		bureaury.signForm(*pardon);
		std::cout << "\nUNSIGNED FORM:\n" \
				  << *unsigned_shrubbery << std::endl;

		std::cout << "SIGNED FORM:\n" \
				  << *signed_shrubbery << std::endl;
		
		std::cout << "ROBOTOMY:\n" \
				  << *robotomy << std::endl;

		std::cout << "PARDON:\n" \
				  << *robotomy << std::endl;
		std::cout << "--------------------------\n";

		std::cout << "\n---------EXECUTING--------\n";
		bureaury.executeForm(*signed_shrubbery);
		bureaury.executeForm(*unsigned_shrubbery);
		bureaury.executeForm(*robotomy);
		bureaury.executeForm(*pardon);
		std::cout << "--------------------------\n";

		std::cout << "\n---------DESTRUCTION----------\n";
		delete signed_shrubbery;
		delete unsigned_shrubbery;
		delete pardon;
		delete robotomy;
	}
	catch(const std::exception& e)
	{
		std::cerr << "\nERROR: " << e.what() << '\n';
	}
	std::cout << "--------------------------\n";
	return 0;
}