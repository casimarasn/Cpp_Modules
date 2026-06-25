#ifndef FILE_HPP
# define FILE_HPP

# include <iostream>
# include <string>
# include <fstream>
class	File
{
	private:
		std::string	_fileName;
		std::string	_s1;
		std::string	_s2;
	public:
		File(std::string fileName, std::string s1, std::string s2);
		~File();
		void	replace();

};

#endif