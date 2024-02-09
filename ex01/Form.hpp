/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:59:22 by ndesprez          #+#    #+#             */
/*   Updated: 2024/02/09 16:58:24 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Bureaucrat;

class Form
{
private:
    std::string const   _name;
    bool                _signed;
    int const           _siGrade;
    int const           _exGrade;
public:
    Form();
	Form(Form const &instance);
	Form	&operator=(Form const &instance);
	~Form();

    Form(std::string const &name, int siGrade, int exGrade);

    class   GradeTooHighException: public std::exception
    {
        public:
            virtual char const  *what(void) const throw();
    };
    class   GradeTooLowException: public std::exception
    {
        public:
            virtual char const  *what(void) const throw();
    };

    std::string getName() const;
    bool        getSigned() const;
    int         getSiGrade() const;
    int         getExGrade() const;

    void    beSigned(Bureaucrat const &b);

};

std::ostream	&operator<<(std::ostream &str, Form const &instance);
