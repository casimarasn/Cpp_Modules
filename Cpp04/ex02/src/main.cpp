# include "Dog.hpp"
# include "Cat.hpp"
# include "WrongCat.hpp"

int	main()
{
	Animal *farm[4];

	farm[0] = new Dog();
	farm[1] = new Cat();
	farm[2] = new Dog();
	farm[3] = new Cat();


	Dog	dog1;

	dog1.getBrain()->setIdeas(0, "I am a border collie");

	Dog	dog2(dog1);
	
	std::cout	<< dog1.getBrain()->getIdeas(0)
				<< std::endl
				<< dog2.getBrain()->getIdeas(0)
				<< std::endl;

	dog2.getBrain()->setIdeas(0, "I am an annoying yorkshire terrier");

	std::cout	<< dog1.getBrain()->getIdeas(0)
				<< std::endl
				<< dog2.getBrain()->getIdeas(0)
				<< std::endl;

	Cat	cat1;

	cat1.getBrain()->setIdeas(0, "I am a Persian");

	Cat	cat2(cat1);
	
	std::cout	<< cat1.getBrain()->getIdeas(0)
				<< std::endl
				<< cat2.getBrain()->getIdeas(0)
				<< std::endl;

	cat2.getBrain()->setIdeas(0, "I am a truly Egiptian cat");

	std::cout	<< cat1.getBrain()->getIdeas(0)
				<< std::endl
				<< cat2.getBrain()->getIdeas(0)
				<< std::endl;

	for (int i = 0; i < 4; i++)
		delete farm[i];

	return (0);
}