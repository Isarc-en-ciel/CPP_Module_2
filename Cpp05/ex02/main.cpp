/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:58:22 by iwaslet           #+#    #+#             */
/*   Updated: 2025/11/03 18:09:18 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	try
	{
		Form		b8014("amsterixsme", 80, 6);
		Form		a38("oh", 0, 45);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	gg("laurent", 2);
		Bureaucrat	loser("filip", 149);
		Bureaucrat	joe("John", 75);
		Form		b8014("amsterixsme", 80, 6);
		
		gg.signForm(b8014);
		joe.signForm(b8014);
		loser.signForm(b8014);
	}
	catch (std::exception& f)
	{
		std::cerr << f.what() << std::endl;
	}
}
