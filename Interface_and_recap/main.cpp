/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 13:35:06 by yanflous          #+#    #+#             */
/*   Updated: 2025/10/11 19:29:22 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "AMateria.hpp"
# include "IMateriaSource.hpp"
# include "MateriaSource.hpp"
# include "ICharacter.hpp"
# include "Character.hpp"
# include "Ice.hpp"
# include "Cure.hpp"

// int main()
// {
// 	MateriaSource* src = new MateriaSource();

// 	Ice	*I = new Ice();
// 	Cure *C = new Cure();
// 	Ice II;
	
// 	src->learnMateria(I);	// add Ice to templates[0]
// 	src->learnMateria(C);	// add cure to templates[1]
// 	src->learnMateria(&II); // add Ice to templatesp[2]	

	
// 	src->print_temp_members();

// 	ICharacter *me = new Character("me");  // i stoped here.
// 	/*
// 		create the "me" just for using the equip() methode to
// 		add a createMateria into the equip -> inventory[] list
// 	*/

// 	/*
// 		here we create a tmp pointer that pointes to a new created
// 		AMateria* createMateria(std::string const & type);
		
// 	*/
// 	AMateria *tmp;

// 	// >>> test for invalid type
// 	tmp = src->createMateria("hello");
// 	if (tmp == 0)
// 		std::cout << "not in the templates list" << std::endl;
	
// 	/*
// 		-> about createMateria() is create an return a New heap AMateria
// 		type if the type match the type in the templates
// 		and then use the methode of "clone" reather the type
// 		is "ice" or "Cure", all the "clone" do is return a copy
// 		of the object Cure or Ice just in the heap, that's all
// 		about the clone methode in the Ice and Cure, rgith?

// 		-> about the equip() is a Buckup like, right?
// 		add AMateria Ice() or Cure() type in that buckup
// 		just to free it latter that's all about the equip
// 	*/
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
	
// 	// test to give it a NULL address
// 	me->equip(NULL);

// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);
	
// 	ICharacter* bob = new Character("bob");

// 	me->use(0, *bob);
// 	me->use(1, *bob);

	
// 	std::cout << "------- Other tests ------" << std::endl;
// 	// Deep copy test
// 	Character* clone_test = new Character("copy");
// 	*clone_test = *(Character*)me;

// 	// Full inventory test
// 	for (int i = 0; i < 4; i++)
// 	    me->equip(src->createMateria("ice"));  // 5th one shouldn't fit

// 	// Unequip and re-equip
// 	me->unequip(0);
// 	me->equip(src->createMateria("cure"));

// 	src->print_temp_members();


// 	// NULL handling
// 	me->use(0, *bob);  // After unequip
// 	me->equip(NULL);   // Already tested but good to keep

// 	delete bob;
// 	delete me;
// 	delete src;
// 	delete I;
// 	delete C;
// 	// delete clone_test;

// 	return 0;
// }



int main()
{
    MateriaSource* src = new MateriaSource();

    Ice	*I = new Ice();
    Cure *C = new Cure();
    Ice II;
    
    src->learnMateria(I);
    src->learnMateria(C);
    src->learnMateria(&II);

    ICharacter *me = new Character("me");
    AMateria *tmp;

    tmp = src->createMateria("hello");
    if (tmp == 0)
        std::cout << "not in the templates list" << std::endl;
    
    tmp = src->createMateria("ice");
    me->equip(tmp);
    
    me->equip(NULL);

    tmp = src->createMateria("cure");
    me->equip(tmp);
    
    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    std::cout << "------- Other tests ------" << std::endl;
    
    // Character* clone_test = new Character("copy");
    // *clone_test = *(Character*)me;

	// all about the leak start here //
    // for (int i = 0; i < 4; i++)
    //     me->equip(src->createMateria("ice"));

    // me->unequip(0);
    // me->equip(src->createMateria("cure"));

    // src->print_temp_members();

    // me->use(0, *bob);
    // me->equip(NULL);

	Character* me_copy = new Character("copy");
	*me_copy = *(Character*)me;

	// Only fill empty slots (0, 1 already have materias)
	me->equip(src->createMateria("ice"));
	me->equip(src->createMateria("ice"));

	me->unequip(0);
	me->equip(src->createMateria("cure"));

	me->use(0, *bob);
	me->equip(NULL);
	
	delete me_copy;
	delete bob;
	delete me;
	delete src;
	delete I;
	delete C;

    return 0;
}
