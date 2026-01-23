/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 16:10:07 by iwaslet           #+#    #+#             */
/*   Updated: 2026/01/16 14:15:04 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
# include <algorithm>
# include <vector>

template <typename T>

void easyfind(T container, int tofind)
{
	if (std::find(container.begin(), container.end(), tofind) != container.end())
		std::cout << "bjr, je sui lo" << std::endl;
	else
		std::cout << "wola il est pas la" << std::endl;
}

#endif