/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:20:46 by iwaslet           #+#    #+#             */
/*   Updated: 2025/12/11 17:41:46 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	srand(time(NULL));

	switch(rand() % 3)
	{
		case 0:
		{
			std::cout << "A generated" << std::endl;
			return (new A);
		}
		case 1:
		{
			std::cout << "B generated" << std::endl;
			return (new B);
		}
		default:
		{
			std::cout << "C generated" << std::endl;
			return (new C);
		}
	}
}

static void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A identified" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B identified" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C identified" << std::endl;
}

static void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A identified" << std::endl;
	}
	catch(...)
	{}
	try
	{
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B identified" << std::endl;
	}
	catch(...)
	{}
	try
	{
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C identified" << std::endl;
	}
	catch(...)
	{}
}
	
int main()
{
	Base *x = generate();
	Base *y = generate();
	Base *z = generate();

	identify(x);
	identify(y);
	identify(z);

	identify(*x);
	identify(*y);
	identify(*z);

	delete(x);
	delete(y);
	delete(z);

	return(0);
}