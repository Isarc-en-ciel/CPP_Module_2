/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 18:09:23 by iwaslet           #+#    #+#             */
/*   Updated: 2026/02/19 19:26:29 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <cstring>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cctype>
#include <cstdlib>
#include <map>
#include <ctime>

std::map<std::string, float> 	create_data(std::ifstream &file, int flag);
int								check_file(std::ifstream &file);
float							check_value(std::string value, int flag);
int								check_date(std::string date);
int								convert_value(std::string &str);
bool							is_leap_year(int year);
bool							is_valid_day(int day, int month, int year);

void 	calculate_btc(std::map<std::string, float> &data_file, std::ifstream &file, int flag);
float	find_value(std::string date, std::map<std::string, float> &data_file);
float	calc_result(float input_val, float data_val);

#endif