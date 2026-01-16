/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 16:12:48 by iwaslet           #+#    #+#             */
/*   Updated: 2026/01/16 16:59:04 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <iterator>
#include <vector>

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
	int shortestSpan()
	{
		int e = 0;
		int d = 0;
		if (vect.size() == 0|| vect.size() == 1)
			throw NoSpan();
		for (int j = *vect.end(); vect[j]; j--)
		{
			for (int i = 0; vect[i]; i++)
			{
				if (i != j)
					d = std::distance(&vect[i], &vect[j]);
				if (d < e)
					e = d;
			}
		}
		return(e);
	};
	int longestSpan()
	{
		int d = 0;
		int e = 0;
		if (vect.size() == 0|| vect.size() == 1)
			throw NoSpan();
		for (int j = *vect.end(); vect[j]; j--)
		{
			for (int i = 0; vect[i]; i++)
			{
				if (i != j)
					d = std::distance(&vect[i], &vect[j]);
				if (d > e)
					e = d;
			}
		}
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