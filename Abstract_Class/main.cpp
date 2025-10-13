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

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	// AAnimal AA_obj;
	
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();

	AAnimal *Animal_arry[100];
	
	std::cout << "\n------------------- Brain -----------------------"
			<< std::endl;

	for (int i = 0; i < 100; i++)
	{
		if (i < 50)
			Animal_arry[i] = new Dog;
		else
			Animal_arry[i] = new Cat;
	}

	for (int i = 0; i < 100; i++)
		Animal_arry[i]->makeSound();

	std::cout << "\n----------- Testing Assignment Operator -----------" << std::endl;

	Dog *Dog_copy = new Dog;

	*Dog_copy = *(Dog *)Animal_arry[0];
	Dog_copy->makeSound();

	std::cout << "\n------------------ Deleting -------------------"
			<< std::endl;

	delete i;
	delete j;
	delete Dog_copy;
	for (int i = 0; i < 100; i++)
	{
		if (Animal_arry[i])
			delete Animal_arry[i];
	}
	
    return 0;
}