/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 18:12:35 by iwaslet           #+#    #+#             */
/*   Updated: 2026/03/03 12:00:45 by iwaslet          ###   ########.fr       */
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
	check_contents(input);
}

void	check_contents(std::string input)
{
	std::stringstream ss(input);
	std::string elem;
	while (ss >> elem)
	{
		if (is_nbr(elem) == 1)
			throw GeneralErrors(INVALID);
	}
}

int is_nbr(std::string elem)
{
	unsigned int i = 0;
	while(i < elem.length())
	{
		if (!isdigit(elem[i]))
			return(1);
		i++;
	}
	return (0);
}

int	Jacobsthal(int k)
{
	return round((pow(2, k + 1) + pow(-1, k)) / 3);
}

const char	*GeneralErrors::what() const throw()
{
	switch (_err)
	{
		case INVALID:
			return ("Invalid input");
		case SYNTAX:
			return ("Syntax wrong");
		case DOUBLES:
			return ("At least one number included twice");
		default:
			return ("Error");
	}
}