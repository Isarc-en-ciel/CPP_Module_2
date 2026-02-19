/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 18:07:59 by iwaslet           #+#    #+#             */
/*   Updated: 2026/02/19 19:26:05 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char** av)
{
	if (ac < 2)
	{
		std::cerr << "no file" << std::endl;
		return (-1);
	}
	std::ifstream file_exec(av[1]);
	std::ifstream file_data("data.csv");
	if (check_file(file_exec) || check_file(file_data))
		std::cerr << "something wrong with file" << std::endl;
	std::map<std::string, float> data_file = create_data(file_data, 1);
	calculate_btc(data_file, file_exec, 2);
	return (0);
}
