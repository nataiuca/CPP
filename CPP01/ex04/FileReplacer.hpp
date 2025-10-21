#ifndef FILEREPLACER_HPP
# define  FILEREPLACER_HPP

# include <iostream>
# include <fstream>
# include <string>

class FileReplacer {
private:
	std::string filename;
	std::string s1;
	std::string s2;

public:
	FileReplacer(std::string filename, std::string s1, std::string s2);
	bool replace();
};

#endif