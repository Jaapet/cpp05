/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:59:22 by ndesprez          #+#    #+#             */
/*   Updated: 2024/03/12 16:23:34 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class AForm
{
private:
    std::string const   _name;
    bool                _signed;
    int const           _siGrade;
    int const           _exGrade;
public:
    AForm();
	AForm(AForm const &instance);
	AForm	&operator=(AForm const &instance);
	virtual ~AForm();

    AForm(std::string const &name, int siGrade, int exGrade);

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
    class   FormNotSignedException : public std::exception
    {
        public:
            virtual const char  *what(void) const throw();
    };

    std::string getName() const;
    bool        getSigned() const;
    int         getSiGrade() const;
    int         getExGrade() const;

    void    beSigned(Bureaucrat const &b);

    virtual void    execute(Bureaucrat const &b) const = 0;
};

std::ostream	&operator<<(std::ostream &str, AForm const &instance);
