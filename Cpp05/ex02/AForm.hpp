/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:23:21 by iwaslet           #+#    #+#             */
/*   Updated: 2025/11/03 18:57:13 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <cstring>
# include <cstdlib>
# include <fstream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	protected:
	const std::string name;
	bool	is_signed;
	const int	sign_grade;
	const int	exec_grade;
	public:
	AForm();
	AForm(const std::string name1, const int sg, const int eg);
	AForm(const AForm &inst);
	virtual ~AForm();
	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};
	bool getIS();
	int getSG() const;
	int getEG() const;
	const std::string getName();
	void beSigned(Bureaucrat signer);
	void beExec(const Bureaucrat& exec) const;
	virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream & obj, AForm &inst);