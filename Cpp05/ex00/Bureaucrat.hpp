/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 17:04:32 by iwaslet           #+#    #+#             */
/*   Updated: 2025/11/07 16:04:35 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# include <iostream>
# include <cstring>

class Bureaucrat 
{
	private:
	const std::string name;
	int grade;
	public:
	Bureaucrat();
	Bureaucrat(std::string name1, int grade);
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
	std::string getName();
	int getGrade();
	void upGrade();
	void lowGrade();
};

std::ostream& operator<<(std::ostream & obj, Bureaucrat &inst);

#endif