/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:59:32 by ndesprez          #+#    #+#             */
/*   Updated: 2024/03/13 14:16:51 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat():_name("null"),_grade(150){}

Bureaucrat::Bureaucrat(Bureaucrat const &instance)
{
    *this = instance;
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &instance)
{
    this->_grade = instance._grade;
    return (*this);
}

Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(std::string const &name, int grade):_name(name), _grade(grade)
{
    if (this->_grade < 1)
        throw (Bureaucrat::GradeTooHighException());
    if (this->_grade > 150)
        throw (Bureaucrat::GradeTooLowException());
}

char const  *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade is already max.");
}

char const  *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade is already min.");
}

std::string Bureaucrat::getName() const
{
    return (this->_name);
}
int Bureaucrat::getGrade() const
{
    return (this->_grade);
}

void    Bureaucrat::incGrade()
{
    this->_grade--;
    if (this->_grade < 1)
        throw (Bureaucrat::GradeTooHighException());
}

void    Bureaucrat::decGrade()
{
    this->_grade++;
    if (this->_grade > 150)
        throw (Bureaucrat::GradeTooLowException());
}

void    Bureaucrat::signForm(AForm &f) const
{
    try
    {
        f.beSigned(*this);
        if (f.getSigned())
            std::cout << *this << " signed " << f << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << *this << " couldn't sign " << f << " because " << e.what() << std::endl;
    }
}

void    Bureaucrat::executeForm(AForm const &form) const
{
    try
    {
        form.execute(*this);
        std::cout << *this << " executed " << form << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

std::ostream	&operator<<(std::ostream &str, Bureaucrat const &instance)
{
    return (str << instance.getName() << ", bureaucrat grade " << instance.getGrade());
}