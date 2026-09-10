# include "Dog.hpp"
# include "Cat.hpp"
# include "WrongCat.hpp"

int	main()
{
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
		delete meta;
		delete j;
		delete i;
	}
	{
		Animal *a = new Animal("animal");
		Animal *b = new Dog();
		Animal *c = new Cat();

		a->makeSound();		// generic animal sound
		b->makeSound();		// guau
		c->makeSound();		// ña ña ña

		delete a;
		delete b;
		delete c;
	}

	{
		WrongAnimal *d = new WrongAnimal("Something strange");
		WrongAnimal *e = new WrongCat();

		d->makeSound();
		e->makeSound();

		delete d;
		delete e;
	}


	return (0);
}