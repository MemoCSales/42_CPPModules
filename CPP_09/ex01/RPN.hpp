#ifndef RPN_HPP
# define RPN_HPP
# include <iostream>
# include <fstream>
# include <sstream>
# include <stack>
# include <algorithm>
# include <string>

# define DEBUG 0
# define ERROR_MESSAGE "Error: Incorrect number of arguments."
# define ERROR_PAR "Error"

# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[1;34m"
# define MAGENT		"\033[1;35m"
# define CYAN		"\033[1;36m"
# define WHITE		"\033[1;37m"
# define DEFAULT		"\033[0m"

class RPN {
	private:
		std::stack<int> _stack;
	public:
		RPN(void);
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();
		// Method
		bool parsing(std::string);
		bool validateToken(const std::string&);
		bool isNumberInRange(const std::string&);
		bool solving(std::string);
		bool isValidOperator(const std::string&);
		bool isValidNumber(const std::string&);
};

#endif
