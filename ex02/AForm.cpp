/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:59:32 by ndesprez          #+#    #+#             */
/*   Updated: 2024/03/13 14:11:18 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm():_name("null"), _signed(false), _siGrade(150), _exGrade(150){}

AForm::AForm(AForm const &instance):_name(instance._name), _signed(instance._signed), _siGrade(instance._siGrade), _exGrade(instance._exGrade){}

AForm	&AForm::operator=(AForm const &instance)
{
    this->_signed = instance._signed;
    return (*this);
}

AForm::~AForm(){}

AForm::AForm(std::string const &name, int siGrade, int exGrade):_name(name), _signed(false), _siGrade(siGrade), _exGrade(exGrade)
{
    if (this->_siGrade < 1)
        throw (AForm::GradeTooHighException());
    if (this->_siGrade > 150)
        throw (AForm::GradeTooLowException());
    if (this->_exGrade < 1)
        throw (AForm::GradeTooHighException());
    if (this->_exGrade > 150)
        throw (AForm::GradeTooLowException());
}

char const  *AForm::GradeTooHighException::what() const throw()
{
    return ("Grade too high.");
}

char const  *AForm::GradeTooLowException::what() const throw()
{
    return ("Grade too low.");
}

char const  *AForm::FormNotSignedException::what() const throw()
{
    return ("Form not signed.");
}

std::string AForm::getName() const
{
    return (this->_name);
}

bool AForm::getSigned() const
{
    return (this->_signed);
}

int AForm::getSiGrade() const
{
    return (this->_siGrade);
}

int AForm::getExGrade() const
{
    return (this->_exGrade);
}

void    AForm::beSigned(Bureaucrat const &b)
{
    if (b.getGrade() > this->_siGrade)
        throw (AForm::GradeTooLowException());
    else
        this->_signed = true;
}

std::ostream	&operator<<(std::ostream &str, AForm const &instance)
{
    return (str << instance.getName() << ", signed " << instance.getSigned() << ", grade to sign " << instance.getSiGrade() << ", grade to execute " << instance.getExGrade());
}