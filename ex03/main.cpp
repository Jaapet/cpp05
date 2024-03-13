/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:39:32 by ndesprez          #+#    #+#             */
/*   Updated: 2024/03/13 16:38:10 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main(void)
{
    Intern      intern;

    AForm        *form = intern.makeForm("ShrubberyCreationForm", "Form");
    AForm        *form2 = intern.makeForm("RobotomyRequestForm", "Form2");
    AForm        *form3 = intern.makeForm("PresidentialPardonForm", "Form3");

    std::cout << *form << std::endl;
    std::cout << *form2 << std::endl;
    std::cout << *form3 << std::endl;

    delete form;
    delete form2;
    delete form3;

    try
    {
        AForm   *form4 = intern.makeForm("a", "Form4");
        (void)form4;
    }
    catch (const Intern::UnknownFormException &e)
    {
        std::cerr << e.what() << '\n';
    }

    return (0);
}