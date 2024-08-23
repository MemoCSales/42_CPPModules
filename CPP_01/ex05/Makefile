NAME = harl

CPP			= g++
CPPFLAGS	= -std=c++98
CPPFLAGS	+= -Wall -Wextra -Werror
CPPFLAGS	+= -g

SRC 		= $(wildcard *.cpp)

OBJDIR		= .obj
OBJ			= $(patsubst %.cpp, $(OBJDIR)/%.o, $(SRC))

all: $(NAME)

run: $(NAME)
	@./$(NAME) test.txt hola adios

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

val:
	@if [ -z "$(FILE)" ]; then \
		echo "Error: Please specify a file using 'make val FILE=<filename>'"; \
		exit 1; \
	fi
	valgrind --leak-check=full ./$(NAME) $(FILE)

replace:
	@echo "$(YELLOW) ---Deleting files with .replace extension ---$(DEFAULT)"
	@files=$$(find . -name "*.replace" -type f); \
	for file in $$files; do \
		echo "Deleting $$file"; \
		rm -r "$$file"; \
	done

.PHONY: all clean fclean re replace

# Colors
GREEN			= \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
MAGENTA		= \033[1;35m
CYAN		= \033[1;36m
WHITE		= \033[1;37m
DEFAULT		= \033[0m