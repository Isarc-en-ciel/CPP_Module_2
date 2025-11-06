/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:30:39 by iwaslet           #+#    #+#             */
/*   Updated: 2025/11/06 18:02:12 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery creation", 145, 137), _target("void")
{
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery creation", 145, 137)
{
	this->_target = target;
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &inst) : AForm(inst)
{
	return;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	return;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &inst)
{
	if (this != &inst)
		this->_target = inst._target;
	return(*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	try
	{
		this->beExec(executor);
		std::string create = _target;
		
		create.append("_shrubbery");
		std::ofstream newFile(create.c_str());
		if (!newFile.is_open())
		{
			std::cerr << "Error: Can't open file (っ- ‸ – ς)" << std::endl;
			return;
		}
		newFile << "   /* \n";
    	newFile << "  /*** \n";
    	newFile << " /***** \n";
		newFile << "/******** \n";
		newFile << "  |**| \n";
   		newFile << "  |**| \n";
		newFile.close();	
	}
	catch (std::exception& f)
	{
		std::cout << executor.getName() << " couldn't execute " << this->getName()
		<< " because ";
		std::cerr << f.what() << std::endl;
	}
}