/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 18:09:15 by iwaslet           #+#    #+#             */
/*   Updated: 2026/02/10 16:11:57 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int check_file(std::ifstream &file)
{
	if (!file.is_open())
		return (1);
	return (0);
}

int convert_value(std::string &str)
{
	int value;
	std::stringstream ss(str);
	ss >> value;
	return(value);
}

bool is_leap_year(int is_it)
{
	if (is_it % 4 == 0 && is_it % 100 != 0)
		return (true);
	if (is_it % 400 == 0)
		return (true);
	else
		return (false);
}

std::map<std::string, float> create_data(std::ifstream &file, int flag)
{
	std::map<std::string, float> data;
	std::string line;
	int i = std::string::npos;
	while (getline(file, line)) //skip la 1e ligne
	{
		std::string date;
		std::string value;
		std::string line2(line);
		float nbr;
		if (flag == 1)
			i = line.find(",");
		else
			i = line.find("|");
		if (i != std::string::npos)
			line2[i] = ' ';
		std::stringstream ss(line2);
		ss >> date;
		check_date(date);
		ss >> value; //check que value pas vide
		nbr = check_value(value); // check que value entre 0 et 1000 opur le fichier exec
		data.insert(std::pair<std::string, float>(date, nbr));
	}
	return (data);
}

float	check_value(std::string value)
{
	int i = 0;
	int p = 0;
	while (value[i])
	{
		if (value[i] == '.')
		{
			i++;
			p++;
			if (p > 1)
			exit;//renvoyer une erreur jsp
		}
		if (!std::isdigit(value[i]))
			exit;//
		i++;
	}
	return (std::atof(value.c_str()));
}

void	check_date(std::string date)
{
	int delim = 0;
	while (date.find('-') != std::string::npos)
	{
		delim = date.find('-');
		date[delim] = ' ';
	}
	int year;
	int month;
	int day;
	std::stringstream ss(date);
	ss >> year;
	ss >> month;
	ss >> day;
	if (year == 0 || month == 0 || day == 0)
		exit;//erreur ici
	if (year < 2009 || year > 2026 || month > 12  || day > 31)
		exit;//erreur
	if (!is_valid_day(day, month, year))
		exit;
}

bool is_valid_day(int day, int month, int year)
{
	if (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11))
		return ( false);
	if (month == 2  && day > 29)
		return (false);
	if (day == 29 && month == 2) 
	{
		if (!is_leap_year(year))
			return false;
	}
	return true;
}