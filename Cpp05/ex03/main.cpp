/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:58:22 by iwaslet           #+#    #+#             */
/*   Updated: 2025/11/07 16:16:43 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main()
{
	Bureaucrat	gg("laurent", 2);
	Bureaucrat	joe("John", 75);
	
	AForm* tree;
	AForm* robot;
	AForm* president;
	AForm* nope;
	
	Intern	newbie;
	srand((unsigned)time(0)); 
	
	tree = newbie.makeForm("shrubbery creation", "forest");
	robot = newbie.makeForm("robotomy request", "machine");
	president = newbie.makeForm("presidential pardon", "culprit");
	nope = newbie.makeForm("wola", "（´＿｀）");
	
	gg.signForm(*robot);
	gg.signForm(*president);
	joe.signForm(*tree);

	robot->execute(gg);
	president->execute(gg);
	tree->execute(joe);
	
	delete(tree);
	delete(robot);
	delete(president);
	delete(nope);
}
