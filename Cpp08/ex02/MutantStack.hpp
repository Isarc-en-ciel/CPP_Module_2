/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 16:13:39 by iwaslet           #+#    #+#             */
/*   Updated: 2026/01/23 14:55:06 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>
#include <list>
#include <vector>

template <typename T, class container = std::deque<T> >
class MutantStack : public std::stack<T, container>
{
	public:
	typedef typename std::stack<T, container>::container_type::iterator iterator;
	MutantStack() : std::stack<T, container>()
	{};
	MutantStack(MutantStack<T, container> const &cpy) : std::stack<T, container>(cpy)
	{};
	MutantStack &operator=(MutantStack<T, container> const &src)
	{
		if (this != &src)
			this->c = src.c;
    	return *this;
	};
	iterator begin()
	{
		return this->c.begin();
	};
	iterator end()
	{
		return this->c.end();
	};
	virtual ~MutantStack()
	{};
};

#endif