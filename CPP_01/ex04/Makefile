NAME = sed

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

test: $(NAME)
	@echo "$(YELLOW) ||--------------------------------------------------------------------------------||$(DEFAULT)"
	@echo "$(YELLOW) ||                                    TESTING                                     ||$(DEFAULT)"
	@echo "$(YELLOW) ||--------------------------------------------------------------------------------||$(DEFAULT)"
	@echo "$(GREEN) ||-------------------------------TEST 1: EMPTY FILE-------------------------------||$(DEFAULT)"
	./$(NAME) empty.txt 1 2
	@echo "$(GREEN) ||-------------------------------TEST 2: JUST NEW LINE----------------------------||$(DEFAULT)"
	./$(NAME) newline.txt 1 2
	@echo "$(GREEN) ||--------------------------------TEST 3: NO MATCH: s1----------------------------||$(DEFAULT)"
	./$(NAME) nomatch.txt 42 dog
	@echo "$(GREEN) ||---------------------------------TEST 4: MULTIPLE-------------------------------||$(DEFAULT)"
	./$(NAME) multiple.test ab cd
	@echo "$(GREEN) ||---------------------------------TEST 5: MULTIPLE_2-----------------------------||$(DEFAULT)"
	./$(NAME) multiple.test aaaaa b
	@echo "$(GREEN) ||---------------------------------TEST 6: BEGGINNING-----------------------------||$(DEFAULT)"
	./$(NAME) hello.txt hello Adios
	@echo "$(GREEN) ||---------------------------------TEST 7: END------------------------------------||$(DEFAULT)"
	./$(NAME) hello.txt bye hola
	@echo "$(GREEN) ||---------------------------------TEST 8: LOOONG---------------------------------||$(DEFAULT)"
	./$(NAME) long.txt Lorem 42
	@echo "$(GREEN) ||---------------------------------TEST 9: SPECIAL CHARS--------------------------||$(DEFAULT)"
	./$(NAME) multiple.test '%' '&'
	@echo "$(GREEN) ||---------------------------------TEST 10: CASE SENSITIV-------------------------||$(DEFAULT)"
	./$(NAME) multiple.test Hi hola
	@echo "$(GREEN) ||---------------------------------TEST 11: ONE CHAR s1---------------------------||$(DEFAULT)"
	./$(NAME) multiple.test a x
	@echo "$(GREEN) ||---------------------------------TEST 12: ONE CHAR s2---------------------------||$(DEFAULT)"
	./$(NAME) multiple.test bb y
	@echo "$(GREEN) ||---------------------------------TEST 13: WHITE SPACE---------------------------||$(DEFAULT)"
	./$(NAME) multiple.test " " "_"
	@echo "$(GREEN) ||---------------------------------TEST 14: MULTIPLE------------------------------||$(DEFAULT)"
	./$(NAME) hello.txt hello goodbye
	@echo "$(GREEN) ||---------------------------------TEST 15: EMPTY STRINGS-------------------------||$(DEFAULT)"
	@echo "$(WHITE) Test manually $(DEFAULT)" 

	@echo "$(YELLOW) ||--------------------------------------------------------------------------------||$(DEFAULT)"
	@echo "$(YELLOW) ||                                  END TESTING                                   ||$(DEFAULT)"
	@echo "$(YELLOW) ||--------------------------------------------------------------------------------||$(DEFAULT)"


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