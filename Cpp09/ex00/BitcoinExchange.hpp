/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 18:09:23 by iwaslet           #+#    #+#             */
/*   Updated: 2026/01/30 13:27:55 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <cctype>
#include <map>
#include <ctime>

class BitcoinExchange
{
	private:
	std::map<std::string, std::string> data;
	public:
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange const &cpy);
	BitcoinExchange& operator=(BitcoinExchange const &cpy);
	virtual ~BitcoinExchange();
	std::map<std::string, std::string> analyse_file();
};

#endif