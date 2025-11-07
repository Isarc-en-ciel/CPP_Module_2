/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:31:01 by iwaslet           #+#    #+#             */
/*   Updated: 2025/11/07 16:12:55 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy request", 72, 45), _target("void")
{
	return;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy request", 72, 45)
{
	this->_target = target;
	return;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &inst) : AForm(inst)
{
	return;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	return;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &inst)
{
	if (this != &inst)
		this->_target = inst._target;
	return(*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	try
	{
		this->beExec(executor);
		int random = rand() % 2;
	
		std::cout << "*drilling noises*" << std::endl;
		if (random == 0)
		std::cout << _target << " has been robotomized" << std::endl;
		else
		std::cout << "The robotomy failed" << std::endl;
	}
	catch (std::exception& f)
	{
		std::cout << executor.getName() << " couldn't execute " << this->getName()
		<< " because ";
		std::cerr << f.what() << std::endl;
	}
}