/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:31:33 by iwaslet           #+#    #+#             */
/*   Updated: 2025/11/06 17:25:18 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
	std::string _target;
	public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &inst);
	virtual ~PresidentialPardonForm();
	PresidentialPardonForm& operator=(const PresidentialPardonForm &inst);

	virtual void execute(Bureaucrat const &executor) const;
};