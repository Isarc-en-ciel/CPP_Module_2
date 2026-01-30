/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 18:09:15 by iwaslet           #+#    #+#             */
/*   Updated: 2026/01/30 13:20:26 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	return;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &cpy)
{
	(void)cpy;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &cpy)
{
	return(*this);
}

BitcoinExchange::~BitcoinExchange()
{
	return;
}