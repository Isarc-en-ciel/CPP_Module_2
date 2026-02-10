/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 18:07:59 by iwaslet           #+#    #+#             */
/*   Updated: 2026/02/10 15:03:39 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char** av)
{
	if (ac < 2)
		return (-1);
	std::ifstream file_exec(av[1]);
	std::ifstream file_data("data.csv");
	if (check_file(file_exec) || check_file(file_data))
		std::cerr << "something wrong with file" << std::endl;
	std::map<std::string, float> data_file = create_data(file_data, 1);
	std::map<std::string, float> exec_file = create_data(file_exec, 2);
}

//str_cmp pour comparer les dates, si date + grande, check que date avant existe
//if !date.find str_cmp pour trouver la + proche