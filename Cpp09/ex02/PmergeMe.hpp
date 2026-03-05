/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 18:12:19 by iwaslet           #+#    #+#             */
/*   Updated: 2026/03/03 16:43:44 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cstring>
#include <climits>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <complex>
#include <vector>
#include <deque>
#include <algorithm>

enum e_errors
{
	INVALID,
	SYNTAX,
	DOUBLES
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
void	check_contents(std::string input);
int 	is_nbr(std::string elem);
int		Jacobsthal(int k);

template <typename type>
void check_doubles(type &container);

template <typename type>
void fill_cont(type& container,std::string input);

template <typename type>
void fct_insert(type &main, type &pend, int odd, type &left, type &container, bool is_odd, int order);

template <typename type>
void	sort(type& container);

template <typename type>
void	print_container(type& container);

template <typename type>
void insert_fct(type& container, int to_insert);

template <typename type>
type sort_FJ(type &container);

#endif