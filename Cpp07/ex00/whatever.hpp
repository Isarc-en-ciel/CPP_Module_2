/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 20:45:28 by iwaslet           #+#    #+#             */
/*   Updated: 2025/12/11 20:57:55 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>
#include <string>

template <typename type> void swap(type x, type y)
{
	type z;
	
	z = x;
	x = y;
	y = z;
}

template <typename type> type min(type x, type y)
{
	if (x == y)
		return(y);
	return(x < y) ? x : y;
}

template <typename type> type max(type x, type y)
{
	if (x == y)
		return(y);
	return(x > y) ? x : y;
}

#endif