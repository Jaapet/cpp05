/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:02:37 by ndesprez          #+#    #+#             */
/*   Updated: 2024/03/13 16:35:44 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){}

Intern::Intern(Intern const &instance)
{
    *this = instance;
}

Intern	&Intern::operator=(Intern const &instance)
{
	*this = instance;
    return (*this);
}

Intern::~Intern(){}

char const  *Intern::UnknownFormException::what() const throw()
{
    return ("Unknown form.");
}

AForm *Intern::makeForm(std::string const &formName, std::string target)
{
	std::string tab[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};

	for (int i = 0; i < 3; i++)
	{
		if (formName == tab[i])
		{
			std::cout << "Intern creates " << tab[i] << std::endl;
			switch (i)
			{
				case 0:
					return (new ShrubberyCreationForm(target));
				case 1:
					return (new RobotomyRequestForm(target));
				case 2:
					return (new PresidentialPardonForm(target));
				default :
					break ;
			}
		}
	}
	throw (Intern::UnknownFormException());
	return (NULL);
}
