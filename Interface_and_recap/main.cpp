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

    std::cout << "------- copy assig ------" << std::endl;

	Character* me_copy = new Character("copy");
	*me_copy = *(Character*)me;

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
