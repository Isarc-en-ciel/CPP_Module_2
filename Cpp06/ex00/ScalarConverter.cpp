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

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
	(void)src;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &cpy)
{
	(void)cpy;
	return(*this);
}

ScalarConverter::~ScalarConverter()
{}

static int is_valid(const std::string& str)
{
	unsigned int i = 0;
	int pt = 0;
	if(str[0] == '-')
		i = 1;
	while (i < str.length())
	{
	    if (str[i] == '.')
        {
            pt++;
            if (pt > 1)
                return(0);
        }
		else if (str[i] == 'f')
		{
			 if (i != str.length() - 1)
				return(0);
		}
        else if (!std::isdigit(str[i]))
            return(0);
		i++;
	}
   return(1);
}

void toChar(const std::string& toConvert)
{
	if(std::isprint(static_cast<char>(getChar(toConvert))))
	std::cout << "ASCII: " << (static_cast<char>(getChar(toConvert))) << std::endl;
	else
	std::cout << "char: Non displayable" << std::endl;
}

void toInt(const std::string& toConvert)
{
	if(getChar(toConvert) <= std::numeric_limits<int>::max() && getChar(toConvert) >= -std::numeric_limits<int>::min())
	std::cout << "int is: <" << getChar(toConvert) << ">" << std::endl;
	else
	std::cout << "int is: <" << "impossible" << ">" << std::endl;
}

void toFloat(const std::string& toConvert)
{
	if (getDouble(toConvert) <= std::numeric_limits<float>::max() && getDouble(toConvert) > -std::numeric_limits<float>::max())
	std::cout << "float is: [" << std::fixed << std::setprecision(1) << (static_cast<float>(getDouble(toConvert))) << "f]" << std::endl;
	else
	std::cout << "float is: <" << "impossible" << ">" << std::endl;
}

void toDouble(const std::string& toConvert)
{
	std::cout << "Double is:{" << std::fixed << std::setprecision(1) << getDouble(toConvert) << "} " << std::endl;
}

double getDouble(const std::string& str)
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

long long getChar(const std::string& str)
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

double get_pos_inf() {
	return std::numeric_limits<double>::infinity();
}

double get_neg_inf() {
	return -std::numeric_limits<double>::infinity();
}

double get_nan() {
	return std::numeric_limits<double>::quiet_NaN();
}

void ScalarConverter::convert(const std::string& toConvert)
{
	if ((((static_cast<int>(getDouble(toConvert))) == 0 && toConvert[0] != '0')) || (!is_valid(toConvert) && toConvert.length() > 1) || toConvert.empty())
	{
		int i = 0;
		std::string info[] = { "+inf", "+inff", "-inf", "-inff" , "nanf", "nan", ""};
		while (!info[i].empty())
		{
			SpecialFunc funcs[] = { get_pos_inf, get_pos_inf, get_neg_inf, get_neg_inf, get_nan, get_nan };
			if (info[i] == toConvert)
			{
				std::cout << "double: " << funcs[i]() << std::endl;
				std::cout << "float: " << funcs[i]() << "f" << std::endl;
				std::cout << "char: impossible" << std::endl;
				std::cout << "int:  impossible" << std::endl;
				return;
			}
			i++;
		}
		std::cerr << "INVALID STRING" << std::endl;
		return;
	}
	toChar(toConvert);
	toInt(toConvert);
	toFloat(toConvert);
	toDouble(toConvert);
}
