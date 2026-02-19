/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 18:10:59 by iwaslet           #+#    #+#             */
/*   Updated: 2026/02/19 18:18:21 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char** av)
{
	if (ac < 2)
	{
		std::cerr << "no data provided." << std::endl;
		return (-1);
	}
	std::string str(av[1]);
	std::stack<int> nbrs;
	try
	{
		int result = stack_deal(nbrs, str);
		std::cout << result << std::endl;
		return (result);
	}
	catch(std::exception &err)
	{
		std::cerr << err.what() << std::endl;
	}
	return (0);
}