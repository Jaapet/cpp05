/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:37:14 by ndesprez          #+#    #+#             */
/*   Updated: 2024/03/13 14:13:21 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():AForm::AForm("RobotomyRequestForm", 72, 45), _target("null"){}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &instance):AForm::AForm(instance), _target(instance._target){}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &instance)
{
	AForm::operator=(instance);
	this->_target = instance._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target):AForm::AForm("RobotomyRequestForm", 72, 45), _target(target){}

std::string	RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

void	RobotomyRequestForm::execute(Bureaucrat const &b) const
{
	if (this->getSigned() == false)
        throw AForm::FormNotSignedException();
    else if (b.getGrade() > this->getExGrade())
        throw AForm::GradeTooLowException();
    else
    {
        std::cout << "Drilling noises..." << std::endl;
        srand(time(0));
        if (rand() % 2 == 0)
            std::cout << this->_target << " has been robotomized successfully." << std::endl;
        else
            std::cout << this->_target << " robotomization failed." << std::endl;
    }
}

std::ostream	&operator<<(std::ostream &str, RobotomyRequestForm const &instance)
{
	return (str << instance.getName() << ", signed " << instance.getSigned() << ", sign " << instance.getSiGrade() << ", exec " << instance.getExGrade() << ", target " << instance.getTarget());
}