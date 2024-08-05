NAME = phonebook

CPP			= g++
CPPFLAGS	= -std=c++98
CPPFLAGS	+= -Wall -Wextra -Werror -Iinclude
CPPFLAGS	+= -g

SRCDIR		= src
SRC 		= $(wildcard $(SRCDIR)/*.cpp)

OBJDIR		= .obj
# OBJ			= $(patsubst %.cpp, $(OBJDIR)/%.o, $(SRC))
OBJ			= $(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

all: $(NAME)

run: $(NAME)
	@echo "$(WHITE) ||-----------------------------------------------------------------------------------||$(DEFAULT)"
	@echo "$(WHITE) ||                    📱WELCOME TO YOUR 80's FAVORITE PHONEBOOK📱                    ||$(DEFAULT)"
	@echo "$(WHITE) ||                                                                                   ||$(DEFAULT)"
	@echo "$(WHITE) ||  As usual you have multiple options to interact with your phonebook. These are:   ||$(DEFAULT)"
	@echo "$(WHITE) ||                                                                                   ||$(DEFAULT)"
	@echo "$(WHITE) ||    📥 ADD a new contact     🔍 SEARCH for a specific contact       ⛓️‍💥 EXIT       ||$(DEFAULT)"
	@echo "$(WHITE) ||-----------------------------------------------------------------------------------||$(DEFAULT)"
	@./$(NAME)

test: $(NAME)
	./$(NAME)

$(NAME): $(OBJ)
	@$(CPP) -o "$@" $(CPPFLAGS) $(OBJ)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
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