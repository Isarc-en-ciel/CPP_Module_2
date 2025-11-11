/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 17:04:23 by iwaslet           #+#    #+#             */
/*   Updated: 2025/11/11 14:38:50 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	return;
}

Bureaucrat::Bureaucrat(std::string name1, int grade) : name(name1)
{
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
	this->grade = grade;
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

std::string Bureaucrat::getName() const
{
	return(this->name);
}

int	Bureaucrat::getGrade() const
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

void Bureaucrat::upGrade(int &grade)
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

void Bureaucrat::lowGrade(int &grade)
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

void Bureaucrat::signForm(AForm &paper)
{
	try
	{
		paper.beSigned(*this);
	}
	catch(std::exception& f)
	{
		std::cout << this->getName() << " couldn't sign " << paper.getName()
		<< " because ";
		std::cerr << f.what() << std::endl;
	}
}
