NAME = megaphone

CPP			= g++
CPPFLAGS	= -std=c++98
CPPFLAGS	+= -Wall -Wextra -Werror
CPPFLAGS	+= -g

SRC 		= $(wildcard *.cpp)

OBJDIR		= .obj
OBJ			= $(patsubst %.cpp, $(OBJDIR)/%.o, $(SRC))

all: $(NAME)

run: $(NAME)
	./$(NAME)

test: $(NAME)
	@echo "$(YELLOW) ||------------------------------------------------------------------------------||$(DEFAULT)"
	@echo "$(YELLOW) ||                                    TESTING                                   ||$(DEFAULT)"
	@echo "$(YELLOW) ||------------------------------------------------------------------------------||$(DEFAULT)"
	@echo "\n"
	@echo "$(GREEN) ||------------------------------------TEST 1------------------------------------||$(DEFAULT)"
	./$(NAME) "shhhhh... I think the students are asleep..."
	@echo "$(BLUE) ||------------------------------------TEST 2------------------------------------||$(DEFAULT)"
	./$(NAME) Damnit " ! " "Sorry students, I thought this thing was off."
	@echo "$(RED) ||------------------------------------TEST 3------------------------------------||$(DEFAULT)"
	./$(NAME)
	@echo "$(MAGENTA) ||------------------------------------TEST 4------------------------------------||$(DEFAULT)"
	./$(NAME) "Hola como estas? de donde eres?"
	@echo "$(CYAN) ||------------------------------------TEST 5------------------------------------||$(DEFAULT)"
	./$(NAME) "42" me la "pela" 'completita'
	@echo "$(WHITE) ||------------------------------------TEST 6------------------------------------||$(DEFAULT)"
	./$(NAME) este es @tro "test" maybe does not "work" ?
	@echo "$(YELLOW) ||------------------------------------------------------------------------------||$(DEFAULT)"
	@echo "$(YELLOW) ||                                  END TESTING                                 ||$(DEFAULT)"
	@echo "$(YELLOW) ||------------------------------------------------------------------------------||$(DEFAULT)"

$(NAME): $(OBJ)
	$(CPP) -o "$@" $(CPPFLAGS) $(OBJ)

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	@$(CPP) -o "$@" $(CPPFLAGS) "$<" -c

clean:
	$(RM) $(OBJ)
	-@rmdir $(OBJDIR) 2>/dev/null

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) $(NAME)

.PHONY: all clean fclean re

# Colors
RED			= \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
MAGENTA		= \033[1;35m
CYAN		= \033[1;36m
WHITE		= \033[1;37m
DEFAULT		= \033[0m