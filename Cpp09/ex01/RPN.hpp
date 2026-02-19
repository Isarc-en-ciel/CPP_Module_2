/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 18:11:37 by iwaslet           #+#    #+#             */
/*   Updated: 2026/02/19 17:23:21 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <cstring>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cctype>
#include <cstdlib>
#include <map>
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

class GeneralErrors : public std::exception
{
	private:
		int _err;
	public:
		GeneralErrors(int err = -1) : _err(err) {}
		virtual const char *what() const throw();
};

#endif