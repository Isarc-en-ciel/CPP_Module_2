/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 18:12:41 by iwaslet           #+#    #+#             */
/*   Updated: 2026/02/25 13:50:42 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char** av)
{
	if (ac < 2)
	{
		std::cerr << "no data provided." << std::endl;
		return (-1);
	}
	std::string str(av[1]);
	try
	{
		check_input(av[1]);
	}
	catch(std::exception &err)
	{
		std::cerr << err.what() << std::endl;
	}
	clock_t start_vec = clock();
    std::vector<int> vec;
    //sort_vec(vec);
    clock_t end_vec = clock();
    double time_elapsed_vec = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC;
	/*get the operation time for each container*/
	clock_t start_deque = clock();
    std::deque<int> deque;
    //sort_deque(deque);
    clock_t end_deque = clock();
    double time_elapsed_deque = static_cast<double>(end_deque - start_deque) / CLOCKS_PER_SEC;
	return (0);
}