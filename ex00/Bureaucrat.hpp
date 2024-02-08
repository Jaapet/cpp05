/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:59:22 by ndesprez          #+#    #+#             */
/*   Updated: 2024/02/08 18:07:39 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include <iostream>

class Bureaucrat
{
private:
    std::string _name;
    int         _grade;
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
};

std::ostream	&operator<<(std::ostream &str, Bureaucrat const &instance);

#endif