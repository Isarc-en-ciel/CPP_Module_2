/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:58:22 by iwaslet           #+#    #+#             */
/*   Updated: 2025/11/06 18:07:33 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main()
{
	Bureaucrat	gg("laurent", 2);
	Bureaucrat	joe("John", 75);
	ShrubberyCreationForm		tree("forest");
	RobotomyRequestForm			robot("machine");
	PresidentialPardonForm		president("culprit");
	srand((unsigned)time(0)); 
		
	gg.signForm(robot);
	gg.signForm(president);
	joe.signForm(tree);

	robot.execute(gg);
	president.execute(gg);
	tree.execute(joe);
}
