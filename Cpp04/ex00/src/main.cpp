# include "Dog.hpp"
# include "Cat.hpp"
# include "WrongCat.hpp"

int	main()
{
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
		WrongAnimal *d = new WrongAnimal("Something strage");
		WrongAnimal *e = new WrongCat();

		d->makeSound();
		e->makeSound();

		delete d;
		delete e;
	}


	return (0);
}