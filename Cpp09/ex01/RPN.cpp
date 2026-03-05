/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 18:11:21 by iwaslet           #+#    #+#             */
/*   Updated: 2026/03/03 16:26:09 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

long long	stack_deal(std::stack<long long> &nbrs, std::string str)
{
	std::stringstream ss(str);
	std::string value;
	while (ss >> value)
	{
		if (value.length() != 1)
			throw GeneralErrors(INVALID);
		if (!isdigit(value[0]) && !is_operator(value[0]))
			throw GeneralErrors(INVALID);
		if (isdigit(value[0]))
			nbrs.push(value[0] - '0');
		else if (is_operator(value[0]))
		{
			if (nbrs.size() < 2)
				throw GeneralErrors(SYNTAX);
			long long a = nbrs.top();
			nbrs.pop();
			long long b = nbrs.top();
			nbrs.pop();
			long long to_push = operate(value[0], b, a);
			nbrs.push(to_push);
		}
	}
	if (nbrs.size() > 1)
		throw GeneralErrors(SYNTAX);
	if (nbrs.top() > INT_MAX || nbrs.top() < INT_MIN)
		throw GeneralErrors(LARGE);
	return (nbrs.top());
}

bool	is_operator(char c)
{
	if (c == '+' || c =='-' || c == '/' || c == '*')
		return (true);
	return (false);
}

long long		operate(char c, long long a, long long b)
{
	switch (c)
	{
		case '+':
			return (a + b);
		case '-':
			return (a - b);
		case '*':
			return (a * b);
		case '/':
			if (b == 0)
				throw GeneralErrors();
			return (a / b);
		default:
			throw GeneralErrors();
	}
}

const char	*GeneralErrors::what() const throw()
{
	switch (_err)
	{
		case INVALID:
			return ("Invalid input");
		case SYNTAX:
			return ("Syntax wrong");
		case LARGE:
			return ("yo mamma has too big a heart");
		default:
			return ("Error");
	}
}

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