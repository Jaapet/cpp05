/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:38:02 by ndesprez          #+#    #+#             */
/*   Updated: 2024/03/13 14:09:23 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():AForm::AForm("PresidentialPardonForm", 25, 5), _target("null"){}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &instance):AForm::AForm(instance), _target(instance._target){}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &instance)
{
	AForm::operator=(instance);
	this->_target = instance._target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target):AForm::AForm("PresidentialPardonForm", 25, 5), _target(target){}

std::string	PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}

void	PresidentialPardonForm::execute(Bureaucrat const &b) const
{
	if (this->getSigned() == false)
        throw AForm::FormNotSignedException();
    else if (b.getGrade() > this->getExGrade())
        throw AForm::GradeTooLowException();
    else
        std::cout << "Informs that " << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::ostream	&operator<<(std::ostream &str, PresidentialPardonForm const &instance)
{
	return (str << instance.getName() << ", signed " << instance.getSigned() << ", sign " << instance.getSiGrade() << ", exec " << instance.getExGrade() << ", target " << instance.getTarget());
}