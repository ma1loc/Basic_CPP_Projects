/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 09:45:03 by yanflous          #+#    #+#             */
/*   Updated: 2025/09/12 09:45:11 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Harl.hpp"

int main(int argc, char **argv)
{
	std::string level;

	if (argc != 2)
		return (std::cout << "error: Most"\
			" be one argument." << std::endl, 1);
	level = argv[1];
	if (level.empty())
		return (std::cout << "error: empty argument not valid." << std::endl, 1);

	Harl	harl;
	harl.complain(level);

	return (0);
}
