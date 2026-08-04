# include "Character.hpp"
# include "MateriaSource.hpp"
# include "Cure.hpp"
# include "Ice.hpp"

void testSubject(void)
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("Mary");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	std::cout	<< me->getName() << " ";
	me->use(0, *bob);
	std::cout	<< me->getName() << " ";
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;

}

void	fullInventoryTest(void)
{
	ICharacter* warrior = new Character("Krull");
	IMateriaSource* inventory = new MateriaSource();
	inventory->learnMateria(new Ice);
	for (int i = 0; i <= 4; i++)
	{
		AMateria* tmp = inventory->createMateria("ice");
		if (i == 4)
		{
			std::cout	<< "Testing a new fifth weapon"
						<< std::endl;
			delete tmp;
		}
		else
			warrior->equip(tmp);
	}
	std::cout	<< "Using Slot[4]: "
				<< std::endl;
	ICharacter*	target = new Character("Target");
	std::cout	<< warrior->getName() << " ";
	warrior->use(0, *target);
	std::cout	<< warrior->getName() << " ";
	warrior->use(1, *target);
	std::cout	<< warrior->getName() << " ";
	warrior->use(2, *target);
	std::cout	<< warrior->getName() << " ";
	warrior->use(3, *target);

	/*el siguiente no debe funcionar slots completos*/
	std::cout	<< "el siguiente no debe funcionar slots completos\n";
	std::cout	<< warrior->getName() << " ";
	warrior->use(4, *target);
	delete target;
	delete warrior;
	delete inventory;
}

void	deepCopy(void)
{
	IMateriaSource* inventory = new MateriaSource();
	inventory->learnMateria(new Cure);

	Character* warrior = new Character("Krull");
	AMateria* spell = inventory->createMateria("cure");
	warrior->equip(spell);

	Character* wizard = new Character(*warrior);
	AMateria* dosis = spell;
	warrior->unequip(0);
	delete dosis;
	std::cout	<< "Test: warrior (original) tries to cure "
				<< std::endl;
	ICharacter* bob = new Character("Bob");
	warrior->use(0, *bob);
	//no debe hacer nada porque esta vacio.
	std::cout	<< "Test: wizard (copy) tries to cure "
				<< std::endl;
	std::cout	<< warrior->getName() << " ";
	wizard->use(0, *bob);
	//debe curarse. Usar el poder. paeso es mago joder.. =)
	delete warrior;
	delete wizard;
	delete bob;
	// delete spell;
	delete inventory;
}

int	main(void)
{
	// testSubject();
	fullInventoryTest();
	// deepCopy();
	return (0);
}




