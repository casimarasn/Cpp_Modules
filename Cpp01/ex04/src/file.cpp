# include "file.hpp"

File::File(std::string fileName, std::string s1, std::string s2) : 
_fileName(fileName), _s1(s1), _s2(s2){}

File::~File()
{
	std::cout << "deleted" << std::endl;
}

void	File::replace()
{
	std::ifstream	fname(_fileName.c_str());
	
}
