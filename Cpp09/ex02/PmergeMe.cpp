/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 18:12:35 by iwaslet           #+#    #+#             */
/*   Updated: 2026/02/24 18:19:54 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	check_input(std::string input)
{
	if (input.length() == 0)
		throw GeneralErrors(INVALID);
	int flag = 0;
	for (size_t i = 0; i < input.length(); i++)
	{
		if (!isspace(input[i]))
			flag++;
	}
	if (flag == 0)
		throw GeneralErrors(INVALID);
}

const char	*GeneralErrors::what() const throw()
{
	switch (_err)
	{
		case INVALID:
			return ("Invalid input");
		case SYNTAX:
			return ("Syntax wrong");
		default:
			return ("Error");
	}
}