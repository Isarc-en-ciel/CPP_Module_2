/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 20:45:11 by iwaslet           #+#    #+#             */
/*   Updated: 2026/01/08 18:37:40 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
# include <iostream>

int main()
{
	try
	{
		Array<int> paul(5);
		for (size_t i = 0; i < 5; i++)
		{
			paul[i] = i;
			std::cout << paul[i] << std::endl;
		}
		Array<int> lol;
		lol = paul;
		for (size_t i = 0; i < lol.size(); i++)
		{
			std::cout << lol[i] << std::endl;
		}
		std::cout << paul.size() << std::endl;
		std::cout << lol[6] << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() <<std::endl;
	}
	return(0);
}