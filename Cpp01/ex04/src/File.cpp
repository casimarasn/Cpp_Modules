# include "file.hpp"

File::File(std::string fileName, std::string s1, std::string s2) : 
_fileName(fileName), _s1(s1), _s2(s2){}

File::~File()
{
	std::cout << "deleted" << std::endl;
}

void	File::replace()
{
	std::ifstream	fName(_fileName.c_str());
	if (!fName.is_open())
	{
		std::cout	<< "Error: could not open input file: "
					<< _fileName
					<< std::endl;
		return ;
	}
	std::string	newFile = _fileName + ".replace";
	std::ofstream	replacedFile(newFile.c_str());
	if (!fName.is_open())
	{
		std::cout	<< "Error: could not open output file: "
					<< newFile
					<< std::endl;
		return ;
	}
	std::string line;
	while (std::getline(fName, line))
	{
		size_t	pos = line.find(_s1);
		while (pos != std::string::npos)
		{
			line.erase(pos, _s1.length());
			line.insert(pos, _s2);
			pos = line.find(_s1, pos + _s2.length());
		}
		replacedFile << line << std::endl;
	}
	fName.close();
	replacedFile.close();
}

