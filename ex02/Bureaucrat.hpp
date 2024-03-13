/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:59:22 by ndesprez          #+#    #+#             */
/*   Updated: 2024/03/13 13:35:14 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class AForm;

class Bureaucrat
{
private:
    std::string const   _name;
    int                 _grade;
public:
    Bureaucrat();
	Bureaucrat(Bureaucrat const &instance);
	Bureaucrat	&operator=(Bureaucrat const &instance);
	~Bureaucrat();

    Bureaucrat(std::string const &name, int grade);

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
    int         getGrade() const;

    void    incGrade();
    void    decGrade();

    void    signForm(AForm &f) const;
    void    executeForm(AForm const &form) const;
};

std::ostream	&operator<<(std::ostream &str, Bureaucrat const &instance);
