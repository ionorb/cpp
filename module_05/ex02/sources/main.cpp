/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:38:35 by codespace         #+#    #+#             */
/*   Updated: 2023/04/26 14:41:08 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main()
{
	try
	{
		std::cout << "\n-------CONSTRUCTION-------\n";
		Bureaucrat				cannot_sign("cannot sign", 146);
		Bureaucrat				cannot_exec("cannot exec", 138);
		Bureaucrat				can_everything("can everything", 136);
		ShrubberyCreationForm	signed_shrubbery("house");
		ShrubberyCreationForm	unsigned_shrubbery("home");
		std::cout << "--------------------------\n";

		std::cout << "\n-------BUREAUCRATS--------\n";
		std::cout << "BUREAUCRAT THAT CANT SIGN:\n";
		std::cout << cannot_sign;

		std::cout << "\nBUREAUCRAT THAT CANT EXEC:\n";
		std::cout << cannot_exec;

		std::cout << "\nBUREAUCRAT THAT CAN EXEC:\n";
		std::cout << can_everything;
		std::cout << "--------------------------\n";

		// std::cout << "\n----------BROKEN----------\n";
		// std::cout << "--------------------------\n";
		
		std::cout << "\n----------SIGNING---------\n";
		std::cout << "UNSIGNED FORM:\n" \
				  << unsigned_shrubbery << std::endl;
	
		// signed_shrubbery.beSigned(cannot_sign);
		// signed_shrubbery.beSigned(cannot_exec);
		cannot_sign.signForm(signed_shrubbery);
		cannot_exec.signForm(signed_shrubbery);

		std::cout << "\nSIGNED FORM:\n" \
				  << signed_shrubbery << std::endl;
		std::cout << "--------------------------\n";

		std::cout << "\n---------EXECUTING--------\n";
		// signed_shrubbery.execute(cannot_exec);
		// signed_shrubbery.execute(can_everything);
		// unsigned_shrubbery.execute(cannot_exec);
		// unsigned_shrubbery.execute(can_everything);
	
		cannot_exec.executeForm(signed_shrubbery);
		can_everything.executeForm(signed_shrubbery);
		cannot_exec.executeForm(unsigned_shrubbery);
		can_everything.executeForm(unsigned_shrubbery);
		std::cout << "--------------------------\n";

		std::cout << "\n---------DESTRUCTION----------\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << "\nERROR: " << e.what() << '\n';
	}
	std::cout << "--------------------------\n";
	return 0;
}