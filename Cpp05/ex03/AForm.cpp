/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:23:12 by iwaslet           #+#    #+#             */
/*   Updated: 2025/11/03 18:27:40 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("void"), sign_grade(1), exec_grade(1)
{
	this->is_signed = 0;
	return;
}

AForm::AForm(const std::string name1, const int sg, const int eg) :
name(name1), sign_grade(sg), exec_grade(eg)
{
	if (sg < 1 || eg < 1)
		throw AForm::GradeTooHighException();
	if (sg >150 || eg > 150)
		throw AForm::GradeTooLowException();
	this->is_signed = 0;
	return;
}

AForm::AForm(const AForm &inst) :
name(inst.name), sign_grade(inst.sign_grade), exec_grade(inst.exec_grade)
{
	this->is_signed = inst.is_signed;
	return;
}

AForm::~AForm()
{
	return;
}

bool AForm::getIS() const
{
	return(is_signed);
}

int AForm::getSG() const
{
	return(sign_grade);
}

int AForm::getEG() const
{
	return(exec_grade);
}

const std::string AForm::getName() const
{
	return(name);
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "grade too low";
}

const char* AForm::NotSignedException::what() const throw()
{
	return "form not signed";
}

void AForm::beSigned(Bureaucrat signer)
{
	if (signer.getGrade() > sign_grade)
		throw AForm::GradeTooLowException();
	if (!is_signed)
	{
		is_signed = true;
		std::cout << signer.getName() << " signed " << name << std::endl;
	}
	else 
		std::cout<< signer.getName() << " could not sign " << name << " again" << std::endl;
}

void AForm::beExec(const Bureaucrat& exec) const
{
	if (!is_signed)
		throw AForm::NotSignedException();
	if (exec.getGrade() > exec_grade)
		throw AForm::GradeTooLowException();
}

std::ostream& operator<<(std::ostream & obj, AForm &inst)
{
	obj << "AForm " << inst.getName() << " of sign grade "
	<< inst.getSG() << " and exec grade " << inst.getEG()
	<< " has been signed ? " << inst.getIS();
	return(obj);
}