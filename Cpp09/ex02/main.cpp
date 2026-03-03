/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 18:12:41 by iwaslet           #+#    #+#             */
/*   Updated: 2026/03/03 13:14:02 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "PmergeMe.tpp"

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
		clock_t start_vec = clock();
		std::vector<int> vec;
		fill_cont(vec, av[1]);
		//sort(vec);
		vec = sort_FJ(vec);
		clock_t end_vec = clock();
		double time_elapsed_vec = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC;
		
		clock_t start_deque = clock();
		std::deque<int> deque;
		fill_cont(deque, av[1]);
		//sort(deque);
		deque = sort_FJ(deque);
		clock_t end_deque = clock();
		double time_elapsed_deque = static_cast<double>(end_deque - start_deque) / CLOCKS_PER_SEC;
		print_container(vec);
		print_container(deque);
		std::cout << "Times are " << time_elapsed_vec << " and " << time_elapsed_deque << std::endl;
	}
	catch(std::exception &err)
	{
		std::cerr << err.what() << std::endl;
	}
	return (0);
}