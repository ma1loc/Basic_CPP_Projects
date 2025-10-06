/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 18:28:36 by yanflous          #+#    #+#             */
/*   Updated: 2025/10/06 13:48:33 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	// (void)i;
	// (void)j;

	Animal *Animal_arry[100];
	
	std::cout << "\n------------------- Brain -----------------------"
			<< std::endl;

	for (int i = 0; i < 100; i++)
	{
		if (i <= 50)
			Animal_arry[i] = new Dog;
		else
			Animal_arry[i] = new Cat;
	}

	std::cout << "\n----------- Testing Assignment Operator -----------" << std::endl;
		Dog dog1;
		Dog dog2;
		dog2 = dog1;

	std::cout << "\n------------------ Deleting -------------------"
			<< std::endl;

	delete i;
	delete j;
	for (int i = 0; i < 100; i++)
	{
		if (Animal_arry[i])
			delete Animal_arry[i];
	}
	
    return 0;
}