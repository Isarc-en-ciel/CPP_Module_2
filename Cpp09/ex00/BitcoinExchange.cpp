/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 18:09:15 by iwaslet           #+#    #+#             */
/*   Updated: 2026/02/20 16:42:07 by iwaslet          ###   ########.fr       */
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
	size_t i = 0;
	getline(file, line);
	while (getline(file, line))
	{
		std::string date;
		std::string value;
		std::string line2(line);
		float nbr;
		int date_flag;
		if (flag == 1)
			i = line.find(",");
		else
			i = line.find("|");
		if (i != std::string::npos)
			line2[i] = ' ';
		std::stringstream ss(line2);
		ss >> date;
		date_flag = check_date(date);
		if (date_flag != 0)
			date = "invalid";
		ss >> value;
		if (value.length() == 0)
			value = "invalid";
		nbr = check_value(value, flag);
		data.insert(std::pair<std::string, float>(date, nbr));
	}
	return (data);
}

float	check_value(std::string value, int flag)
{
	int i = 0;
	int p = 0;
	float nbr;
	if (value == "invalid")
		return (-4);
	while (value[i])
	{
		if (value[i] == '.')
		{
			i++;
			p++;
			if (p > 1)
			return (-1);
		}
		if (!std::isdigit(value[i]))
			return (-1);
		i++;
	}
	nbr = std::atof(value.c_str());
	if (flag == 2)
		if (nbr < 0 || nbr > 1000)
			return (-2);
	return (nbr);
}

int	check_date(std::string date)
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
		return (-1);
	if (year < 2009 || month > 12  || day > 31)
		return (-1);
	if (!is_valid_day(day, month, year))
		return (-1);
	return(0);
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

void calculate_btc(std::map<std::string, float> &data_file, std::ifstream &file, int flag)
{
	std::string line;
	size_t i = 0;
	getline(file, line);
	while (getline(file, line))
	{
		std::string date;
		std::string value;
		std::string line2(line);
		float nbr;
		int date_flag;
		i = line.find("|");
		if (i != std::string::npos)
			line2[i] = ' ';
		std::stringstream ss(line2);
		ss >> date;
		date_flag = check_date(date);
		if (date_flag != 0)
			date = "invalid";
		ss >> value;
		if (value.length() == 0)
			value = "invalid";
		nbr = check_value(value, flag);
		float a = find_value(date, data_file);
		float result = calc_result(nbr, a);
		if (a > 0 && result > 0)
			std::cout << date << " => " << nbr << " = " << result << std::endl;
	}
}

float	find_value(std::string date, std::map<std::string, float> &data_file)
{
	if (date == "invalid")
		return (-1);
	std::map<std::string, float>::iterator it;
	it = data_file.begin();
	while (it != data_file.end())
	{
		if (strcmp(date.c_str(), it->first.c_str()) == 0)
			return (it->second);
		if (strcmp(date.c_str(), it->first.c_str()) < 0)
		{
			if (it != data_file.begin())
			{
				it--;	
				return(it->second);	
			}
			else
			{
				std::cerr << "No correspondant value" << std::endl;
				return (-4);
			}
		}
		it++;
	}
	return(47115.93);
}

float	calc_result(float input_val, float data_val)
{
	if (input_val == -4)
		std::cerr << "No correspondant value" << std::endl;
	if (input_val == -2)
		std::cerr << "Value out of scope" << std::endl;
	if (input_val == -1)
		std::cerr << "Invalid value" << std::endl;
	if (data_val < 0)
	{
		std::cerr << "Date does not exist" << std::endl;
		data_val = -data_val;
	}
	return (input_val * data_val);
}
