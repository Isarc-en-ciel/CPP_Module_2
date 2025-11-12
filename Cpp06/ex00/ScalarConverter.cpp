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

void ScalarConverter::convert(std::string toConvert)
{
	toChar(toConvert);
	toInt(toConvert);
	toFloat(toConvert);
	toDouble(toConvert);
}


void ScalarConverter::toChar(std::string toConvert)
{
	std::cout << "Char : " << std::endl;
	try{
		if (1)
			throw std::runtime_error("coucou");
	}
	catch(std::exception&e){
		std::cout << e.what() << std::endl;
	}
}

void ScalarConverter::toInt(std::string toConvert)
{
	std::cout << "Int : " << std::endl;
}

void ScalarConverter::toFloat(std::string toConvert)
{
	std::cout << "Float : " << std::endl;
}

void ScalarConverter::toDouble(std::string toConvert)
{
	std::cout << "Double : " << std::endl;
}
