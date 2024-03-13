/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:36:15 by ndesprez          #+#    #+#             */
/*   Updated: 2024/03/12 16:24:01 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <fstream>

#define tree "\
                                  # #### ####\n\
                                ### /#|### |/####\n\
                               ##\\/ / ||/##/_/##/_#\n\
                             ###  \\/###|/ \\/ # ###\n\
                           ##_\\_\\#\\_\\## | #/###_/_####\n\
                          ## #### # \\ #| /  #### ##/##\n\
                           __#_--###`  |{,###---###-~\n\
                                     \\ }{\n\
                                      }}{\n\
                                      }}{\n\
                                      {{}\n\
                                , -=-~{ .-^- _\n\
                                      `}\n\
                                       {\n\
"

class ShrubberyCreationForm : public AForm
{
private:
	std::string	_target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(ShrubberyCreationForm const &instance);
	ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &instance);
	virtual ~ShrubberyCreationForm();

	ShrubberyCreationForm(std::string const &target);

	std::string	getTarget() const;

  virtual void    execute(Bureaucrat const &b) const;

};

std::ostream	&operator<<(std::ostream &str, ShrubberyCreationForm const &instance);


