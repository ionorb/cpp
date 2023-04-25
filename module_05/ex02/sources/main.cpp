/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:38:35 by codespace         #+#    #+#             */
/*   Updated: 2023/04/25 09:37:07 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

int	main()
{
	try
	{
		std::cout << "\n-------CONSTRUCTION-------\n";
		Bureaucrat	high_grade_crat("high crat", 10);
		Bureaucrat	low_grade_crat("low crat", 100);
		AForm		hard_form("hard form", 11, 1);
		AForm		easy_form("easy form", 101, 1);
		AForm		medium_form("medium form", 99, 1);
		AForm		extreme_form("extreme form", 9, 1);
		std::cout << "--------------------------\n";

		std::cout << "\n---------PRINTING----------\n";
		std::cout << "HIGH GRADE BUREAUCRAT:\n";
		std::cout << "getname: " << high_grade_crat.getName();
		std::cout << "\ngetgrade: " << high_grade_crat.getGrade();
		std::cout << "\n<< operator: " << high_grade_crat;
		
		std::cout << "\nLOW GRADE BUREAUCRAT:\n";
		std::cout << "getname: " << low_grade_crat.getName();
		std::cout << "\ngetgrade: " << low_grade_crat.getGrade();
		std::cout << "\n<< operator: " << low_grade_crat;

		std::cout << "\nHARD FORM:\n";
		std::cout << "getname: " << hard_form.getName();
		std::cout << "\nstatus: " << hard_form.getSignStatus();
		std::cout << "\nsign grade: " << hard_form.getSignGrade();
		std::cout << "\nexec grade: " << hard_form.getExecGrade();
		std::cout << "\n<< operator:\n" << hard_form;
		
		std::cout << "\nEASY FORM:\n";
		std::cout << "getname: " << easy_form.getName();
		std::cout << "\nstatus: " << easy_form.getSignStatus();
		std::cout << "\nsign grade: " << easy_form.getSignGrade();
		std::cout << "\nexec grade: " << easy_form.getExecGrade();
		std::cout << "\n<< operator:\n" << easy_form;
		
		std::cout << "\nMEDIUM FORM:\n";
		std::cout << "getname: " << medium_form.getName();
		std::cout << "\nstatus: " << medium_form.getSignStatus();
		std::cout << "\nsign grade: " << medium_form.getSignGrade();
		std::cout << "\nexec grade: " << medium_form.getExecGrade();
		std::cout << "\n<< operator:\n" << medium_form;

		std::cout << "\nEXTREME FORM:\n";
		std::cout << "getname: " << extreme_form.getName();
		std::cout << "\nstatus: " << extreme_form.getSignStatus();
		std::cout << "\nsign grade: " << extreme_form.getSignGrade();
		std::cout << "\nexec grade: " << extreme_form.getExecGrade();
		std::cout << "\n<< operator:\n" << extreme_form;
		std::cout << "--------------------------\n";

		// std::cout << "\n----------BROKEN----------\n";
		// Bureaucrat	broken_crat("boop", -34);
		// Bureaucrat	broken_crat2("boop2", 3434);
		// Form		broken_form("broken", 0, 1);
		// Form		broken_form2("broken2", 151, 1);
		// std::cout << "--------------------------\n";
		
		std::cout << "\n----------SIGNING---------\n";
		high_grade_crat.signForm(hard_form);
		high_grade_crat.signForm(easy_form);
		high_grade_crat.signForm(medium_form);
		high_grade_crat.signForm(extreme_form);
		low_grade_crat.signForm(hard_form);
		low_grade_crat.signForm(easy_form);
		low_grade_crat.signForm(medium_form);
		low_grade_crat.signForm(extreme_form);
		std::cout << "--------------------------\n";

		std::cout << "\n---------PRINTING----------\n";
		std::cout << "HIGH GRADE BUREAUCRAT:\n";
		std::cout << "getname: " << high_grade_crat.getName();
		std::cout << "\ngetgrade: " << high_grade_crat.getGrade();
		std::cout << "\n<< operator: " << high_grade_crat;
		
		std::cout << "\nLOW GRADE BUREAUCRAT:\n";
		std::cout << "getname: " << low_grade_crat.getName();
		std::cout << "\ngetgrade: " << low_grade_crat.getGrade();
		std::cout << "\n<< operator: " << low_grade_crat;

		std::cout << "\nHARD FORM:\n";
		std::cout << "getname: " << hard_form.getName();
		std::cout << "\nstatus: " << hard_form.getSignStatus();
		std::cout << "\nsign grade: " << hard_form.getSignGrade();
		std::cout << "\nexec grade: " << hard_form.getExecGrade();
		std::cout << "\n<< operator:\n" << hard_form;
		
		std::cout << "\nEASY FORM:\n";
		std::cout << "getname: " << easy_form.getName();
		std::cout << "\nstatus: " << easy_form.getSignStatus();
		std::cout << "\nsign grade: " << easy_form.getSignGrade();
		std::cout << "\nexec grade: " << easy_form.getExecGrade();
		std::cout << "\n<< operator:\n" << easy_form;
		
		std::cout << "\nMEDIUM FORM:\n";
		std::cout << "getname: " << medium_form.getName();
		std::cout << "\nstatus: " << medium_form.getSignStatus();
		std::cout << "\nsign grade: " << medium_form.getSignGrade();
		std::cout << "\nexec grade: " << medium_form.getExecGrade();
		std::cout << "\n<< operator:\n" << medium_form;

		std::cout << "\nEXTREME FORM:\n";
		std::cout << "getname: " << extreme_form.getName();
		std::cout << "\nstatus: " << extreme_form.getSignStatus();
		std::cout << "\nsign grade: " << extreme_form.getSignGrade();
		std::cout << "\nexec grade: " << extreme_form.getExecGrade();
		std::cout << "\n<< operator:\n" << extreme_form;
		std::cout << "--------------------------\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << "\nERROR: " << e.what() << '\n';
	}
	return 0;
}