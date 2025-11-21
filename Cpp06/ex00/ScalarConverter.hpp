/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:05:24 by iwaslet           #+#    #+#             */
/*   Updated: 2025/11/21 15:54:51 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <ostream>
#include <ctype.h>
#include <iomanip>
#include <limits.h>

class ScalarConverter
{
	public:
	static void convert(const std::string& toConvert);
	static void toChar(const std::string& toConvert);
	static void toInt(const std::string& toConvert);
	static void toFloat(const std::string& toConvert);
	static void toDouble(const std::string& toConvert);
	
	static double getDouble(const std::string& str);
	static long long getChar(const std::string& str);
};

#endif