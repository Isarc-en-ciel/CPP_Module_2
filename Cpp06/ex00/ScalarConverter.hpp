/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:05:24 by iwaslet           #+#    #+#             */
/*   Updated: 2025/12/03 17:25:47 by iwaslet          ###   ########.fr       */
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
#include <limits>

class ScalarConverter
{
	private:
	ScalarConverter();
	ScalarConverter(ScalarConverter const &src);
	ScalarConverter &operator=(ScalarConverter const &cpy);
	virtual ~ScalarConverter();
	public:
	static void convert(const std::string& toConvert);
};

void toChar(const std::string& toConvert);
void toInt(const std::string& toConvert);
void toFloat(const std::string& toConvert);
void toDouble(const std::string& toConvert);

double getDouble(const std::string& str);
long long getChar(const std::string& str);

typedef double (*SpecialFunc)();
double get_pos_inf();
double get_neg_inf();
double get_nan();

#endif