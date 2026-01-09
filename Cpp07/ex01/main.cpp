/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 20:45:05 by iwaslet           #+#    #+#             */
/*   Updated: 2025/12/19 15:32:55 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
	int list[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	char word[5]= {'h', 'e', 'l', 'l', 'o'};
	std::cout << "before +1" << std::endl;
	iter(list, 10, show_value<int>);
	std::cout << "after +1" << std::endl;
	iter(list, 10, add<int>);
	iter(list, 10, show_value<int>);
	std::cout << "word" << std::endl;
	iter(word, 5, show_value<char>);
	std::cout << "word after +1" << std::endl;
	iter(word, 5, add<char>);
	iter(word, 5, show_value<char>);
	return(0);
}