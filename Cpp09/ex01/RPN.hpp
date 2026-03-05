/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 18:11:37 by iwaslet           #+#    #+#             */
/*   Updated: 2026/03/03 16:25:48 by iwaslet          ###   ########.fr       */
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
#include <climits>

enum e_errors
{
	INVALID,
	SYNTAX,
	LARGE
};

long long		stack_deal(std::stack<long long> &nbrs, std::string str);
bool			is_operator(char c);
long long		operate(char c, long long a, long long b);
void			check_input(std::string input);

class GeneralErrors : public std::exception
{
	private:
		int _err;
	public:
		GeneralErrors(int err = -1) : _err(err) {}
		virtual const char *what() const throw();
};

#endif