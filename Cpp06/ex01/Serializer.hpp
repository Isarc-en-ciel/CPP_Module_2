/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:19:28 by iwaslet           #+#    #+#             */
/*   Updated: 2025/11/28 15:59:04 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>

typedef struct s_Data
{
	void	*ptr;
} Data;

class Serializer
{
	private:
	Serializer();
	Serializer(Serializer const &src);
	Serializer &operator=(Serializer const &cpy);
	virtual ~Serializer();
	public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif