/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:37:39 by ndesprez          #+#    #+#             */
/*   Updated: 2024/03/13 13:11:05 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string	_target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(PresidentialPardonForm const &instance);
	PresidentialPardonForm	&operator=(PresidentialPardonForm const &instance);
	virtual ~PresidentialPardonForm();

	PresidentialPardonForm(std::string const &target);

	std::string	getTarget() const;

	virtual void    execute(Bureaucrat const &b) const;

};

std::ostream	&operator<<(std::ostream &str, PresidentialPardonForm const &instance);