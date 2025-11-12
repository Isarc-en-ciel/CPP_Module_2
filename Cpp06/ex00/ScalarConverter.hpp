/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:05:24 by iwaslet           #+#    #+#             */
/*   Updated: 2025/11/12 17:00:16 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter
{
	public:
	static void convert(std::string toConvert);
	static void toChar(std::string toConvert);
	static void toInt(std::string toConvert);
	static void toFloat(std::string toConvert);
	static void toDouble(std::string toConvert);
	
};

#endif