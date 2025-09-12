/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 18:42:52 by yanflous          #+#    #+#             */
/*   Updated: 2025/09/12 11:03:01 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

int main()
{
    std::string string;
    std::string *stringPTR;
    
    string = "HI THIS IS BRAIN";
    stringPTR = &string;
    std::string &stringREF = string;

    std::cout << "The memory address of the string variable"
            << ": " << &string << std::endl;
            
    std::cout << "The memory address held by stringPTR"
            << ": " << stringPTR << std::endl;

    std::cout << "The memory address held by stringREF"
            << ": " << &stringREF << std::endl;

    std::cout << "\n";

    std::cout << "The value of the string variable -> " 
                << string << std::endl;
    std::cout << "The value pointed to by stringPTR -> "
                << *stringPTR << std::endl;
    std::cout << "The value pointed to by stringREF-> "
                << stringREF << std::endl;


}