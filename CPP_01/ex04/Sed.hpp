#ifndef SED_HPP
# define SED_HPP


# include <string>
# include <iostream>
# include <fstream>
# include <cstdlib>

# define DEBUG	0

# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[1;34m"
# define MAGENT		"\033[1;35m"
# define CYAN		"\033[1;36m"
# define WHITE	 	"\033[1;37m"
# define DEFAULT	"\033[0m"


void	    validateArgs(int argc, char **argv);
std::string fileNameWithoutExtension(std::string &filename);
std::string readFileContent(char **argv);
std::string replaceString(std::string &originalString, std::string &s1, std::string &s2);

#endif