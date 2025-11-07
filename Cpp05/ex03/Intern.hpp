/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:59:36 by iwaslet           #+#    #+#             */
/*   Updated: 2025/11/07 15:13:21 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

# include <iostream>
# include "AForm.hpp"

class AForm;

class Intern
{
	public:
	Intern();
	Intern (Intern &inst);
	~Intern();
	Intern &operator=(const Intern &inst);
	AForm *makeForm(std::string type, std::string target);
};

#endif