/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 17:04:32 by iwaslet           #+#    #+#             */
/*   Updated: 2025/11/06 17:09:52 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <cstring>
#include "AForm.hpp"

class AForm;

class Bureaucrat 
{
	private:
	std::string name;
	int grade;
	public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat &inst);
	~Bureaucrat();
	Bureaucrat &operator=(const Bureaucrat &inst);
	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};
	std::string getName() const;
	int getGrade() const;
	void upGrade(int &grade);
	void lowGrade(int &grade);
	void signForm(AForm &paper);
};

std::ostream& operator<<(std::ostream & obj, Bureaucrat &inst);