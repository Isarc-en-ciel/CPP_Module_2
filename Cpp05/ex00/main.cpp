/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:58:22 by iwaslet           #+#    #+#             */
/*   Updated: 2025/10/29 16:37:01 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	try {
		
		Bureaucrat	gg("laurent", 2);
		Bureaucrat	loser("filip", 149);
		Bureaucrat	joe("John", 75);

		std::cout << gg.getName() << " has grade: " << gg.getGrade() << std::endl;
		gg.lowGrade();
		std::cout << gg.getName() << " has grade: " << gg.getGrade() << std::endl;
		std::cout << loser.getName() << " has grade: " << loser.getGrade() << std::endl;
		loser.upGrade();
		std::cout << loser.getName() << " has grade: " << loser.getGrade() << std::endl;
		std::cout << joe.getName() << " has grade: " << joe.getGrade() << std::endl;
		
		Bureaucrat	god("*:･ﾟ✧", 0);
		
		std::cout << god.getName() << " has grade: " << god.getGrade() << std::endl;
	}
	catch(std::exception& e) {
		std::cerr << e.what() <<std::endl;
	}
	try {
		
		Bureaucrat	dumpster("（´＿｀）", 151);
		
		std::cout << dumpster.getGrade() << std::endl;
		dumpster.lowGrade();
		std::cout << dumpster.getGrade() << std::endl;
		
	}
	catch(std::exception& e) {
		std::cerr << e.what() <<std::endl;
	}
}
