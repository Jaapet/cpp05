/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:02:26 by ndesprez          #+#    #+#             */
/*   Updated: 2024/03/13 16:20:26 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
public:
	Intern();
	Intern(Intern const &instance);
	Intern	&operator=(Intern const &instance);
	~Intern();

    AForm *makeForm(std::string const &formName, std::string target);

	class   UnknownFormException: public std::exception
    {
        public:
            virtual char const  *what(void) const throw();
    };
};
