/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:37:18 by ndesprez          #+#    #+#             */
/*   Updated: 2024/03/13 13:56:06 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
private:
	std::string	_target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(RobotomyRequestForm const &instance);
	RobotomyRequestForm	&operator=(RobotomyRequestForm const &instance);
	virtual ~RobotomyRequestForm();

	RobotomyRequestForm(std::string const &target);

	std::string	getTarget() const;

	virtual void    execute(Bureaucrat const &b) const;

};

std::ostream	&operator<<(std::ostream &str, RobotomyRequestForm const &instance);