/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:31:25 by iwaslet           #+#    #+#             */
/*   Updated: 2025/11/03 21:49:27 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential pardon", 25, 5), _target("void")
{
	return;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential pardon", 25, 5)
{
	this->_target = target;
	return;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &inst) : AForm(inst)
{
	return;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	return;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &inst)
{
	if (this != &inst)
		this->_target = inst._target;
	return(*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	try
	{
		this->beExec(executor);
		std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	}
	catch (std::exception& f)
	{
		std::cout << executor->getName() << " couldn't execute " << this.getName()
		<< " because ";
		std::cerr << f.what() << std::endl;
	}
}