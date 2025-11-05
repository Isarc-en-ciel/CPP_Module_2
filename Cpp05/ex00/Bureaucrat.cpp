/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 17:04:23 by iwaslet           #+#    #+#             */
/*   Updated: 2025/10/29 15:43:08 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	return;
}

Bureaucrat::Bureaucrat(std::string name1, int grade) : name(name1)
{
	// try
	// {
		if (grade > 150)
			throw GradeTooLowException();
		if (grade < 1)
			throw GradeTooHighException();
		this->grade = grade;
// 	}
// 	catch(std::exception& e)
// 	{
// 		std::cerr << e.what() << std::endl;
// 	}
// 	return;
}

Bureaucrat::Bureaucrat(Bureaucrat &inst) : name(inst.name)
{
	this->grade = inst.grade;
	return;
}

Bureaucrat::~Bureaucrat()
{
	return;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &inst)
{
	if (this != &inst)
		this->grade = inst.grade;
	return (*this);
}

std::string Bureaucrat::getName()
{
	return(this->name);
}

int	Bureaucrat::getGrade()
{
	return(this->grade);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

void Bureaucrat::upGrade()
{
	try
	{
		if (grade > 1)
			grade -= 1;
		else
			throw GradeTooHighException();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void Bureaucrat::lowGrade()
{
	try
	{
		if (grade < 150)
			grade += 1;
		else
			throw GradeTooLowException();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream & obj, Bureaucrat &inst)
{
	obj << inst.getName() << " , Bureaucrat grade " << inst.getGrade();
	return obj;
}