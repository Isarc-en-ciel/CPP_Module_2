/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:59:24 by iwaslet           #+#    #+#             */
/*   Updated: 2025/11/07 16:05:37 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
	return;
}

Intern::Intern(Intern &inst)
{
	(void) inst;
	return;
}

Intern::~Intern()
{
	return;
}

Intern& Intern::operator=(const Intern &inst)
{
	(void) inst;
	return(*this);
}

AForm *Intern::makeForm(std::string type, std::string target)
{
	AForm *form = NULL;

    AForm* (Intern::*targets[])(std::string target) = {&Intern::newPresidentialPardon, &Intern::newRobotomyRequest, &Intern::newShrubberyCreation};
    std::string forms[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
    
    for (int i = 0; i < 3; i++)
    {
        if (type == forms[i])
        	form = (this->*targets[i])(target);
    }
	if (!form)
		std::cout << "Form "<< type <<" doesn't exist" << std::endl;
	else
		std::cout << "Intern creates "<< type << " form" << std::endl;
	return form;
}

AForm *Intern::newPresidentialPardon(const std::string target)
{
	return(new PresidentialPardonForm(target));
}

AForm *Intern::newRobotomyRequest(const std::string target)
{
	return(new RobotomyRequestForm(target));
}

AForm *Intern::newShrubberyCreation(const std::string target)
{
	return(new ShrubberyCreationForm(target));
}