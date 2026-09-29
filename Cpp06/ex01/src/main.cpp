# include "Serializer.hpp"

int	main(void)
{
	Data	*miData = new Data();
	miData->_name = "Batman";
	miData->_age = 30;

	std::cout	<< "\n------MEMORY DIRECTION------"
				<< std::endl;
	std::cout	<< miData << std::endl;

	std::cout	<< "\n------CONTENT------\n"
				<< "age-> " << miData->_age << std::endl
				<< "name-> " << miData->_name << std::endl
				<< std::endl;

	std::cout	<< "\n------NUMBER CAST------"
				<< std::endl;
	uintptr_t	num = Serializer::serialize(miData);
	std::cout	<< num << std::endl;

	std::cout	<< "\n------MEMORY DIRECTION------"
				<< std::endl;
	miData = Serializer::deserialize(num);
	std::cout	<<miData << std::endl;

	std::cout	<< "\n------RESULT------\n"
				<< "age-> " << miData->_age << std::endl
				<< "name-> " << miData->_name << std::endl
				<< std::endl;

	delete miData;
}
