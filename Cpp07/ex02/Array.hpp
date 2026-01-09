/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 20:47:50 by iwaslet           #+#    #+#             */
/*   Updated: 2026/01/09 15:46:34 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template <typename T> class Array
{
	private:
	unsigned int _n;
	T* array;
	
	public:
	Array() : _n(0), array(NULL)
	{};
	Array(unsigned int n) : _n(n)
	{
		array = new T[n];
	};
	~Array()
	{
		delete[] array;
	};
	Array(Array const &src)
	{
		_n = src._n;
		array = new T[_n];
		for (unsigned int i = 0; i < _n; i++)
		{
			array[i] = src.array[i];
		}
	};
	Array &operator=(Array const &cpy)
	{
		if (this != &cpy)
		{
			_n = cpy._n;
			array = new T[_n];
			for (unsigned int i = 0; i < _n; i++)
				array[i] = cpy.array[i];
		}
		return(*this);
	};
	T &operator[](unsigned int index)
	{
		if (index >= _n)
			throw std::runtime_error("ho nooo");
		return(array[index]);
	};
	T &operator[](unsigned int index) const
	{
		if (index >= _n)
			throw std::runtime_error("ho nooo");
		return(array[index]);
	};
	unsigned int size() const
	{
		return(_n);
	};
};

#endif