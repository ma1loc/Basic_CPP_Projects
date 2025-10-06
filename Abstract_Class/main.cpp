/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 18:28:36 by yanflous          #+#    #+#             */
/*   Updated: 2025/10/06 16:33:04 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "AAnimal.hpp"

int main()
{	
	// AAnimal aa;
	const AAnimal *aa_Dog = new Dog;
	const AAnimal *aa_Cat = new Cat;

	std::cout << "\n-------------------- Sounds --------------------"
			<< std::endl;

	aa_Dog->makeSound();
	aa_Cat->makeSound();

	AAnimal *AAnimal_arry[100];
	
	std::cout << "\n------------------- Brain -----------------------"
			<< std::endl;

	for (int i = 0; i < 100; i++)
	{
		if (i <= 50)
			AAnimal_arry[i] = new Dog;
		else
			AAnimal_arry[i] = new Cat;
	}

	std::cout << "\n----------- Testing Assignment Operator -----------" << std::endl;
		Dog dog1;
		Dog dog2;
		dog2 = dog1;

	std::cout << "\n------------------ Deleting -------------------"
			<< std::endl;

	delete aa_Dog;
	delete aa_Cat;
	for (int i = 0; i < 100; i++)
	{
		if (AAnimal_arry[i])
			delete AAnimal_arry[i];
	}
	
    return 0;
}
