/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:05:14 by iwaslet           #+#    #+#             */
/*   Updated: 2025/11/12 16:58:38 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string& toConvert) //comportement particulier inf/nan
{
	toChar(toConvert);
	toInt(toConvert);
	toFloat(toConvert);
	toDouble(toConvert);
}


void ScalarConverter::toChar(const std::string& toConvert)
{
	if(std::isprint(static_cast<char>(getChar(toConvert))))
		std::cout << "ASCII: " << (static_cast<char>(getChar(toConvert))) << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

void ScalarConverter::toInt(const std::string& toConvert)
{
	if(getChar(toConvert) <= INT_MAX && getChar(toConvert) >= INT_MIN)
		std::cout << "int is: <" << getChar(toConvert) << ">" << std::endl;
	else
		std::cout << "int is: <" << "impossible" << ">" << std::endl;
}

void ScalarConverter::toFloat(const std::string& toConvert)
{
	if (getDouble(toConvert) < static_cast<double>(1 << 24) && getDouble(toConvert) > static_cast<double>(-(1 << 24)))
		std::cout << "float is: [" << std::fixed << std::setprecision(1) << (static_cast<float>(getDouble(toConvert))) << "f]" << std::endl;
	else
		std::cout << "float is: <" << "impossible" << ">" << std::endl;
}

void ScalarConverter::toDouble(const std::string& toConvert) //pas de gestion des limites
{
	std::cout << "Double is:{" << std::fixed << std::setprecision(1) << getDouble(toConvert) << "} " << std::endl;
}

double ScalarConverter::getDouble(const std::string& str)
{
	double d;
	char c;

	std::stringstream ste(str);
	if(str.size() == 1 && !std::isdigit(str[0]))
	{
		ste >> c;
		return(static_cast<double>(c));
	}
	ste >> d;
	return(d);
}

long long ScalarConverter::getChar(const std::string& str)
{
	long long l;
	char c;

	std::stringstream ste(str);
	if(str.size() == 1 && !std::isdigit(str[0]))
		ste >> c;
	else
	{
		ste >> l;
		return(l);
	}
	return(static_cast<long long>(c));
}