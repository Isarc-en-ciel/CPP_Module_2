/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 16:10:10 by iwaslet           #+#    #+#             */
/*   Updated: 2026/01/23 17:23:53 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

// int main()
// {
// 	MutantStack<int> mstack;
// 	mstack.push(5);
// 	mstack.push(17);
// 	std::cout << mstack.top() << std::endl;
// 	mstack.pop();
// 	std::cout << mstack.size() << std::endl;
// 	mstack.push(3);
// 	mstack.push(5);
// 	mstack.push(737);
// 	//[...]
// 	mstack.push(0);
// 	MutantStack<int>::iterator it = mstack.begin();
// 	MutantStack<int>::iterator ite = mstack.end();
// 	++it;
// 	--it;
// 	while (it != ite)
// 	{
// 	std::cout << *it << std::endl;
// 	++it;
// 	}
// 	return 0;
// }

// int main()
// {
// 	std::list<int> mstack;
// 	mstack.push_back(5);
// 	mstack.push_back(17);
// 	std::cout << mstack.back() << std::endl;
// 	mstack.pop_back();
// 	std::cout << mstack.size() << std::endl;
// 	mstack.push_back(3);
// 	mstack.push_back(5);
// 	mstack.push_back(737);
// 	//[...]
// 	mstack.push_back(0);
// 	std::list<int>::iterator it = mstack.begin();
// 	std::list<int>::iterator ite = mstack.end();
// 	++it;
// 	--it;
// 	while (it != ite)
// 	{
// 	std::cout << *it << std::endl;
// 	++it;
// 	}
// 	return 0;
// }

void	testCopy( void )
{
	MutantStack<std::string, std::vector<std::string> > mstack;
	mstack.push("Hello");
	mstack.push("word");
	mstack.push("save");
	mstack.push("me");
	mstack.push("pls");
	MutantStack<std::string, std::vector<std::string> >	tmp;
	tmp = mstack;
	MutantStack<std::string, std::vector<std::string> >::iterator it = tmp.begin();
	while (it != tmp.end())
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << "\n\n";
}

void	vectorContainer( void )
{
	MutantStack<std::string, std::vector<std::string> > mstack;
	mstack.push("Hello");
	mstack.push("word");
	mstack.push("save");
	mstack.push("me");
	mstack.push("pls");
	MutantStack<std::string, std::vector<std::string> >::iterator it = mstack.begin();
	while (it != mstack.end())
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << "\n\n";
}

void	listContainer( void )
{
	MutantStack<int, std::list<int> > mstack;
	int i = 0;
	while (i < 100)
	{
		mstack.push(i);
		++i;
	}
	MutantStack<int, std::list<int> >::iterator it = mstack.begin();
	while (it != mstack.end())
	{
		std::cout << *it << ", ";
		++it;
	}
	std::cout << std::endl;
}

void	deffContainer( void )
{
	MutantStack<int > mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

int main()
{
	deffContainer();
	listContainer();
	vectorContainer();
	testCopy();
	return 0;
}