/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 14:45:52 by iwaslet           #+#    #+#             */
/*   Updated: 2026/03/03 13:14:37 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename type>
void check_doubles(type &container)
{
	unsigned int i = 0;
	while (i < container.size())
	{
		unsigned int j = i + 1;
		while (j < container.size())
		{
			if (container[i] == container[j])
				throw GeneralErrors(DOUBLES);
			j++;
		}
		i++;
	}
}

template <typename type>
void fill_cont(type& container,std::string input)
{
	std::stringstream ss(input);
	int elem;
	while (ss >> elem)
	{
		container.push_back(elem);
	}
	check_doubles(container);
}

template <typename type>
void fct_insert(type &main, type &pend, int odd, type &left, type &container, bool is_odd, int order)
{
	typename type::iterator end;

	if (pend.size() == 1)
	{
        end = std::upper_bound(main.begin(), main.end(), *pend.begin());
        main.insert(end, *pend.begin());
	}
	else if (pend.size() > 1)
	{
		size_t jc = 3;
        size_t count = 0;
        size_t idx;
        size_t decrease;

		while (!pend.empty())
		{
            idx = Jacobsthal(jc) - Jacobsthal(jc - 1);
            if (idx > pend.size())
                idx = pend.size();

            decrease = 0;
            while (idx)
			{
				end = main.begin();
                if (Jacobsthal(jc + count) - decrease <= main.size())
                    end = main.begin() + Jacobsthal(jc + count) - decrease;
                else
                    end = main.end();
                end = std::upper_bound(main.begin(), end, *(pend.begin() + idx - 1));
                main.insert(end, *(pend.begin() + idx - 1));
                pend.erase(pend.begin() + idx - 1);

                idx--;
                decrease++;
                count++;
			}
			jc++;
		}
	}
	type new_cont;
	if (is_odd)
	{
        end = std::upper_bound(main.begin(), main.end(), odd);
        main.insert(end, odd);
    }
	for (typename type::iterator i = main.begin(); i != main.end(); i++)
	{
        typename type::iterator it = std::find(container.begin(), container.end(), *i);
        new_cont.insert(new_cont.end(), it - (order - 1), it + 1);
    }
	new_cont.insert(new_cont.end(), left.begin(), left.end());
    container = new_cont;
}

template <typename type>
void	sort(type& container)
{
	static int order = 1;

	int unit_size = container.size() / order;
	if (unit_size < 2)
		return;
	bool has_odd = (unit_size % 2 == 1);
	typename type::iterator start = container.begin();
    typename type::iterator end = container.begin() + ((order * unit_size) - (has_odd * order));
	for (typename type::iterator it = start; it < end; it += (order * 2)) {
        if (*(it + (order - 1)) > *(it + ((order * 2) - 1))) {
            for (int i = 0; i < order; i++) {
                std::swap(*(it + i), *(it + i + order));
            }
        }
    }
	order *= 2;
	sort(container);
	order /= 2;
	
	type main;
	type temp;
	type rest;
	int odd_nbr = 0;

	main.push_back(*(start + order - 1));
	main.push_back(*(start + order * 2 - 1));
	
	for (typename type::iterator it = start + order * 2; it < end; it += order) {
        temp.push_back(*(it + order - 1));
        it += order;
        main.push_back(*(it + order - 1));
    }
	if (has_odd)
        odd_nbr = *(end + order - 1);
	rest.insert(rest.end(), end + (order * has_odd), container.end());

	if (has_odd || !temp.empty())
        fct_insert(main, temp, odd_nbr, rest, container, has_odd, order);
}

template <typename type>
void	print_container(type& container)
{
	size_t i = 0;
	while (i < container.size() - 1)
	{
		std::cout << container[i] << ", ";
		i++;
	}
	std::cout << container[i] << std::endl;
}

template <typename type>
type sort_FJ(type &container)
{
	if (container.size() <= 1)
		return (container);
	bool has_odd = false;
	int odd_nbr = 0;
	type main;
	type temp;
	if (container.size() % 2 == 1)
	{
		odd_nbr = container.back();
		has_odd = true;
		container.pop_back();
	}
	for (size_t i = 0; i < container.size(); i = i + 2)
	{
		if (container[i] > container[i + 1])
		{
			main.push_back(container[i]);
			temp.push_back(container[i + 1]);
		}
		else
		{
			main.push_back(container[i + 1]);
			temp.push_back(container[i]);
		}
	}

	main = sort_FJ(main);

	for (size_t i = 0; i < temp.size(); i++)
	{
		insert_fct(main, temp[i]);
	}
	if (has_odd)
	{
		insert_fct(main, odd_nbr);
	}
	return (main);
}

template <typename type>
void insert_fct(type& container, int to_insert)
{
	typename type::iterator it = upper_bound(container.begin(), container.end(), to_insert);
	container.insert(it, to_insert);
}