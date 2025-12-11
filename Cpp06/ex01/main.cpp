/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:20:41 by iwaslet           #+#    #+#             */
/*   Updated: 2025/12/11 20:42:27 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>
#include <ostream>

int	main()
{
	int a = 25;
	Data d= {&a};
	uintptr_t raw = Serializer::serialize(&d);
	std::cout << &d << " : " <<*(int*)(d.ptr) << std::endl;
	std::cout <<"raw: " << raw << std::endl;
	std::cout << Serializer::deserialize(raw) << std::endl;
	Data *D =	Serializer::deserialize(raw);
	std::cout << D << " : " <<*(int*)(D->ptr) << std::endl;
	
	return (0);
}