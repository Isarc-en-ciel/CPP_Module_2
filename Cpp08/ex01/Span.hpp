/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 16:12:48 by iwaslet           #+#    #+#             */
/*   Updated: 2026/01/20 14:24:47 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <list>

class Span
{
	private:
	unsigned int _size;
	std::vector<int> vect;
	public:
	Span()
	{
		this->_size = 0;
		std::vector<int> vect;
		return;
	};
	Span(unsigned int N)
	{
		this->_size = N;
		std::vector<int> vect;
		return;
	};
	~Span()
	{};
	class NoSpan : public std::exception
	{
		virtual const char *what() const throw();
	};
	class LimitReached : public std::exception
	{
		virtual const char *what() const throw();
	};
	void addNumber(int toAdd)
	{
		if (this->_size == 0)
			throw LimitReached();
		this->vect.push_back(toAdd);
		this->_size --;
	};
	void addMany(std::list<int> my_list)
	{
		if (my_list.size() > this->_size)
			throw LimitReached();
		this->vect.insert(vect.end(), my_list.begin(), my_list.end());
		this->_size -= my_list.size();
	};
	long long shortestSpan()
	{
		long long e = 0;
		long long d = 0;
		if (vect.size() == 0|| vect.size() == 1)
			throw NoSpan();
		std::sort(vect.begin(), vect.end());
		for (std::vector<int>::iterator i = vect.begin(); i + 1 != vect.end(); i++)
		{
			d = *(i + 1) - *(i);
			if (i == vect.begin())
				e = d;
			if (d < e)
				e = d;
		}
		return(e);
	};
	long long longestSpan()
	{
		long long e = 0;
		if (vect.size() == 0|| vect.size() == 1)
			throw NoSpan();
		std::sort(vect.begin(), vect.end());
		e = *(vect.end() - 1) - *(vect.begin());
		return (e);
	};
};

const char* Span::NoSpan::what() const throw()
{
	return "No span to find";
}
const char* Span::LimitReached::what() const throw()
{
	return "Maximum elements reached";
}

#endif