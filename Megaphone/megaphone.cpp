/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 13:36:53 by yanflous          #+#    #+#             */
/*   Updated: 2025/09/05 13:37:54 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
    int     i;
    int     j;
    char    c;

    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        i = 1;
        while (argv[i])
        {
            j = 0;
            while (argv[i][j])
            {
                c = std::toupper(argv[i][j]);
                std::cout << c;
                j++;
            }
            i++;
        }
        std::cout << std::endl;
    }
    return (0);
}
