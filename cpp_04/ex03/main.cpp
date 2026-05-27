/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 15:12:25 by vloureir          #+#    #+#             */
/*   Updated: 2026/03/19 14:50:24 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "AMateria.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main(void)
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("thunder");
	me->equip(tmp);
	tmp = src->createMateria("bone storm");
	me->equip(tmp);
	tmp = src->createMateria("defile");
	me->equip(tmp);
	tmp = src->createMateria("soul reaper");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	
	std::cout << "char name: " << me->getName() << std::endl;
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(4, *bob);
	me->use(-1, *bob);

	std::cout << std::endl;

	Character maria("maria");
	tmp = src->createMateria("cure");
	maria.equip(tmp);
	tmp = src->createMateria("ice");
	maria.equip(tmp);
	tmp = src->createMateria("cure");
	maria.equip(tmp);

	std::cout << "char name: " << maria.getName() << std::endl;
	maria.use(0, *bob);
	maria.use(1, *bob);
	maria.use(2, *bob);
	maria.use(3, *bob);
	{
		std::cout << std::endl << "--- testing deep copy ---" << std::endl;
		ICharacter *thom = new Character("thom");
		tmp = src->createMateria("cure");
		thom->equip(tmp);
		tmp = src->createMateria("cure");
		thom->equip(tmp);
		tmp = src->createMateria("ice");
		thom->equip(tmp);
		tmp = src->createMateria("cure");
		thom->equip(tmp);
		tmp = src->createMateria("cure");
		thom->equip(tmp);
		tmp = src->createMateria("fire");
		thom->equip(tmp);

		std::cout << "char name: " << thom->getName() << std::endl;
		thom->use(0, *bob);
		thom->use(1, *bob);
		thom->use(2, *bob);
		thom->use(3, *bob);
		std::cout << std::endl;
		*static_cast<Character*>(thom) = maria;

		std::cout << "maria unequip: " << thom->getName() << std::endl;
		maria.unequip(1);
		std::cout << "char name: " << thom->getName() << std::endl;
		thom->use(0, *bob);
		thom->use(1, *bob);
		thom->use(2, *bob);
		thom->use(3, *bob);
		delete thom;

		Character test;

		test = *static_cast<Character*>(me);
		test.unequip(1);
		test.unequip(0);
		test.unequip(-30);
		test.unequip(30);
		std::cout << std::endl << "char name: " << test.getName() << std::endl;
		test.use(0, *bob);
		test.use(1, *bob);
		test.use(2, *bob);
		test.use(3, *bob);
	}
	std::cout << std::endl << "--- showing outside variable are unchanged ---" << std::endl << std::endl;
	
	std::cout << "char name: " << me->getName() << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);

	std::cout << std::endl << "char name: " << maria.getName() << std::endl;
	maria.use(0, *bob);
	maria.use(1, *bob);
	maria.use(2, *bob);
	maria.use(3, *bob);

	delete bob;
	delete me;
	delete src;
	
	std::cout << std::endl << "--- materia tests ---" << std::endl << std::endl;
	AMateria *ic = new Ice();
	AMateria *cr = new Cure();

	std::cout << "ice type: "<< ic->getType() << std::endl;
	std::cout << "cure type: "<< cr->getType() << std::endl;
	
	*ic = *cr;

	std::cout << "ice type: "<< ic->getType() << std::endl;
	std::cout << "cure type: "<< cr->getType() << std::endl;

	delete ic;
	delete cr;
	
	return 0;
}