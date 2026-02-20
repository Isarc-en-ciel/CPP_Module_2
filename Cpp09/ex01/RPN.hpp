/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 18:11:37 by iwaslet           #+#    #+#             */
/*   Updated: 2026/02/20 16:46:58 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <cstring>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <stack>

enum e_errors
{
	INVALID,
	SYNTAX
};

int		stack_deal(std::stack<int> &nbrs, std::string str);
bool	is_operator(char c);
int		operate(char c, int a, int b);
void	check_input(std::string input);

class GeneralErrors : public std::exception
{
	private:
		int _err;
	public:
		GeneralErrors(int err = -1) : _err(err) {}
		virtual const char *what() const throw();
};

#endif