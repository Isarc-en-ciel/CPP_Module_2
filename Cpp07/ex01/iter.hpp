/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 20:45:48 by iwaslet           #+#    #+#             */
/*   Updated: 2025/12/19 15:30:38 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template <typename type, typename function>

void iter(type* list, const size_t size, function fct)
{
	if (!list)
		std::cout << "error, no array" << std::endl;
	for (size_t i = 0; i < size; i++)
	{
		fct(list[i]);
	}
}

template <typename type>

void show_value(type& value)
{
	std::cout << value << std::endl;
}

template <typename type>

void add(type& value)
{
	value++;
}

#endif