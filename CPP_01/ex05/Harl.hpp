#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

# define DEBUG 1

# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[1;34m"
# define MAGENT		"\033[1;35m"
# define CYAN		"\033[1;36m"
# define WHITE	 	"\033[1;37m"
# define DEFAULT	"\033[0m"

// typedef void(Harl::*myPointerToMethod) (std::string);

enum Level {
    DEBUG1,
    INFO,
    WARNING,
    ERROR,
    INVALID
};

class Harl
{
private:
    void    debug(void);
    void    info(void);
    void    warning(void);
    void    error(void);
    Level   resolveLevel(const std::string& level);
public:
    Harl();
    ~Harl();

    void    complain(std::string level);
};


#endif