/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 18:28:31 by yanflous          #+#    #+#             */
/*   Updated: 2025/10/06 11:50:33 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Defualt constractor called for Brain"
			<< std::endl;
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Copy Constractor called for Brain"
			<< std::endl;

	for (int i = 0; i < 100; i++)
		this->ideas[i] = copy.ideas[i];
}

Brain	&Brain::operator=(const Brain &copy)
{
    std::cout << "Brain copy assignment called"
			<< std::endl;

	if (this != &copy)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = copy.ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Destractor is called for Brain"
			<< std::endl;
}