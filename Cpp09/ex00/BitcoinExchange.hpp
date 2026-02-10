/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 18:09:23 by iwaslet           #+#    #+#             */
/*   Updated: 2026/02/10 14:56:14 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cctype>
#include <map>
#include <ctime>


std::map<std::string, float> 	create_data(std::ifstream &file, int flag);
int								check_file(std::ifstream &file);
float							check_value(std::string value);
void							check_date(std::string date);
int								convert_value(std::string &str);
bool							is_leap_year(int year);

#endif