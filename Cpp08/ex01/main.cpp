/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 16:10:10 by iwaslet           #+#    #+#             */
/*   Updated: 2026/01/22 15:15:08 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	try
	{
		Span mySpan(5);
		mySpan.addNumber(15);
		mySpan.addNumber(47);
		mySpan.addNumber(25);
		mySpan.addNumber(39);
		mySpan.addNumber(82);
		mySpan.addNumber(73);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
		try
	{
		Span mySpan(5);
		std::list<int> liste;
		liste.push_back(1);
		liste.push_back(2);
		liste.push_back(3);
		liste.push_back(4);
		liste.push_back(5);
		//liste.push_back(6);
		mySpan.addMany(liste);
		std::cout << mySpan.shortestSpan() << std::endl;
		std::cout << mySpan.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Span mySpan(5);
		mySpan.addNumber(15);
		mySpan.addNumber(47);
		mySpan.addNumber(25);
		mySpan.addNumber(39);
		mySpan.addNumber(82);
		std::cout << mySpan.shortestSpan() << std::endl;
		std::cout << mySpan.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}try
	{
		Span mySpan(1);
		mySpan.addNumber(15);
		mySpan.longestSpan();
		mySpan.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Span mySpan(5);
		mySpan.longestSpan();
		mySpan.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}