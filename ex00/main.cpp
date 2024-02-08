/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:39:32 by ndesprez          #+#    #+#             */
/*   Updated: 2024/02/08 18:18:45 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
    /* Throw exception when calling constructor with grade too high */
    {
        try
        {
            Bureaucrat mike("Mike", 0);
            std::cout << mike << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }

    std::cout << "\n --------------------- \n\n";

    /* Throw exception when calling constructor with grade too low */
    {
        try
        {
            Bureaucrat jim("Jim", 151);
            std::cout << jim << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }

    std::cout << "\n --------------------- \n\n";
    
    /* Throw exeception when calling incGrade */
    {    
        try 
        {
            Bureaucrat dur("Dur", 3);
            std::cout << dur << std::endl;
            dur.incGrade();
            std::cout << dur << std::endl;
            dur.incGrade();
            std::cout << dur << std::endl;
            dur.incGrade();
            std::cout << dur << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }

    std::cout << "\n --------------------- \n\n";

    /* Throw exeception when calling decGrade */
    {    
        try 
        {
            Bureaucrat alan("Alan", 149);
            std::cout << alan << std::endl;
            alan.decGrade();
            std::cout << alan << std::endl;
            alan.decGrade();
            std::cout << alan << std::endl;
            alan.decGrade();
            std::cout << alan << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    return (0);
}