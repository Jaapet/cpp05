/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:59:32 by ndesprez          #+#    #+#             */
/*   Updated: 2024/02/09 17:08:59 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form():_name("null"), _signed(false), _siGrade(150), _exGrade(150){}

Form::Form(Form const &instance):_name(instance._name), _signed(instance._signed), _siGrade(instance._siGrade), _exGrade(instance._exGrade){}

Form	&Form::operator=(Form const &instance)
{
    this->_signed = instance._signed;
    return (*this);
}

Form::~Form(){}

Form::Form(std::string const &name, int siGrade, int exGrade):_name(name), _signed(false), _siGrade(siGrade), _exGrade(exGrade)
{
    if (this->_siGrade < 1)
        throw (Form::GradeTooHighException());
    if (this->_siGrade > 150)
        throw (Form::GradeTooLowException());
    if (this->_exGrade < 1)
        throw (Form::GradeTooHighException());
    if (this->_exGrade > 150)
        throw (Form::GradeTooLowException());
}

char const  *Form::GradeTooHighException::what() const throw()
{
    return ("Grade too high");
}

char const  *Form::GradeTooLowException::what() const throw()
{
    return ("Grade too low");
}

std::string Form::getName() const
{
    return (this->_name);
}

bool Form::getSigned() const
{
    return (this->_signed);
}

int Form::getSiGrade() const
{
    return (this->_siGrade);
}

int Form::getExGrade() const
{
    return (this->_exGrade);
}

void    Form::beSigned(Bureaucrat const &b)
{
    if (b.getGrade() > this->_siGrade)
        throw (Form::GradeTooLowException());
    else
        this->_signed = true;
}

std::ostream	&operator<<(std::ostream &str, Form const &instance)
{
    return (str << instance.getName() << ", signed " << instance.getSigned() << ", grade to sign " << instance.getSiGrade() << ", grade to execute " << instance.getExGrade());
}