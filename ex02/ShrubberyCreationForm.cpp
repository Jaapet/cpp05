/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:36:43 by ndesprez          #+#    #+#             */
/*   Updated: 2024/03/13 13:52:16 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():AForm::AForm("ShrubberyCreationForm", 145, 137), _target("null"){}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &instance):AForm::AForm(instance), _target(instance._target){}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &instance)
{
	AForm::operator=(instance);
	this->_target = instance._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target):AForm::AForm("ShrubberyCreationForm", 145, 137), _target(target){}

std::string	ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &b) const
{
	if (this->getSigned() == false)
        throw AForm::FormNotSignedException();
    else if (b.getGrade() > this->getExGrade())
        throw AForm::GradeTooLowException();
	else
	{
		std::ofstream file((_target + "_shrubbery").c_str());
		file << tree << std::endl;
		file.close();
	}
}

std::ostream	&operator<<(std::ostream &str, ShrubberyCreationForm const &instance)
{
	return (str << instance.getName() << ", signed " << instance.getSigned() << ", sign " << instance.getSiGrade() << ", exec " << instance.getExGrade() << ", target " << instance.getTarget());
}