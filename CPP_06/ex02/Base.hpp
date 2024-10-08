#ifndef Base_HPP
# define Base_HPP
# include <iostream>
# include <cstdlib> //for srand() and rand()
# include <ctime> // for time()
# include <unistd.h>
# include <typeinfo>

# define DEBUG 0

# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[1;34m"
# define MAGENT		"\033[1;35m"
# define CYAN		"\033[1;36m"
# define WHITE		"\033[1;37m"
# define DEFAULT		"\033[0m"


// class A;

class Base {
	public:
		virtual ~Base();
};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif


