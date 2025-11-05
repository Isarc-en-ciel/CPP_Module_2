/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:23:21 by iwaslet           #+#    #+#             */
/*   Updated: 2025/11/03 18:08:45 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <cstring>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
	const std::string name;
	bool	is_signed;
	const int	sign_grade;
	const int	exec_grade;
	public:
	Form();
	Form(const std::string name1, const int sg, const int eg);
	Form(const Form &inst);
	~Form();
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
};

std::ostream& operator<<(std::ostream & obj, Form &inst);