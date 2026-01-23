/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 16:10:10 by iwaslet           #+#    #+#             */
/*   Updated: 2026/01/16 14:13:54 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	try
	{
		std::vector<int> vec;

		vec.push_back(7);
		vec.push_back(69 + 8);
		vec.push_back(777);
		vec.push_back(7777);
		vec.push_back(77777);
		easyfind(vec, 77);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::vector<int> vec;

		vec.push_back(42);
		vec.push_back(2 * 21);
		vec.push_back(84 / 2);
		vec.push_back(41 + 1);
		vec.push_back(142 % 100);
		vec.push_back(42 - 23);
		easyfind(vec, 19);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::vector<int> vec;

		vec.push_back(7);
		vec.push_back(69 + 8);
		vec.push_back(777);
		vec.push_back(7777);
		vec.push_back(77777);
		easyfind(vec, 118218);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}