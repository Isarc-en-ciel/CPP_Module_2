/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:23:12 by iwaslet           #+#    #+#             */
/*   Updated: 2025/11/03 18:27:40 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("void"), sign_grade(1), exec_grade(1)
{
	this->is_signed = 0;
	return;
}

Form::Form(const std::string name1, const int sg, const int eg) :
name(name1), sign_grade(sg), exec_grade(eg)
{
	if (sg < 1 || eg < 1)
		throw Form::GradeTooHighException();
	if (sg >150 || eg > 150)
		throw Form::GradeTooLowException();
	this->is_signed = 0;
	return;
}

Form::Form(const Form &inst) :
name(inst.name), sign_grade(inst.sign_grade), exec_grade(inst.exec_grade)
{
	this->is_signed = inst.is_signed;
	return;
}

Form::~Form()
{
	return;
}

bool Form::getIS()
{
	return(is_signed);
}

int Form::getSG() const
{
	return(sign_grade);
}

int Form::getEG() const
{
	return(exec_grade);
}

const std::string Form::getName()
{
	return(name);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "grade too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "grade too low";
}

void Form::beSigned(Bureaucrat signer)
{
	if (signer.getGrade() > sign_grade)
		throw Form::GradeTooLowException();
	if (!is_signed)
	{
		is_signed = true;
		std::cout << signer.getName() << " signed " << name << std::endl;
	}
	else 
		std::cout<< signer.getName() << " could not sign " << name << " again" << std::endl;
}

std::ostream& operator<<(std::ostream & obj, Form &inst)
{
	obj << "Form " << inst.getName() << " of sign grade "
	<< inst.getSG() << " and exec grade " << inst.getEG()
	<< " has been signed ? " << inst.getIS();
	return(obj);
}