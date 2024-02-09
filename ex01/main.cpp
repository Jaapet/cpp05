/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:39:32 by ndesprez          #+#    #+#             */
/*   Updated: 2024/02/09 16:43:15 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    /* Create a form with grade too high */
    {
        try
        {
            Form form0("A99", 0, 5);
            std::cout << form0 << std::endl;
        }
        catch(std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
        
    }

    std::cout << "\n --------------------- \n\n";

    /* Create form and sign it without exceptions */
    {
        try
        {
            Bureaucrat mike("Mike", 15);
            Form form("B58", 20, 45);
            std::cout << mike << std::endl;
            std::cout << form << std::endl;
            mike.signForm(form);
            std::cout << form << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    
    std::cout << "\n --------------------- \n\n";

    /* Create form and try to sign it but the grade is not enough */
    {
        try
        {
            Bureaucrat jon("Jon", 35);
            Form form2("C_303", 20, 45);
            std::cout << jon << std::endl;
            std::cout << form2 << std::endl;
            jon.signForm(form2);
            std::cout << form2 << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    return (0);
}