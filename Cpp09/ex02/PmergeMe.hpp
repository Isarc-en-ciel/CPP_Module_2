/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 18:12:19 by iwaslet           #+#    #+#             */
/*   Updated: 2026/02/25 13:37:52 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cstring>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <deque>

enum e_errors
{
	INVALID,
	SYNTAX
};

class GeneralErrors : public std::exception
{
	private:
		int _err;
	public:
		GeneralErrors(int err = -1) : _err(err) {}
		virtual const char *what() const throw();
};


void	check_input(std::string input);

#endif