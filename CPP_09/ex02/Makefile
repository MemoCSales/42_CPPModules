NAME = PmergeMe

SRC = $(wildcard *.cpp)
INC = $(wildcard *.hpp *.tpp)
OBJDIR = .obj
OBJ = $(patsubst %.cpp, $(OBJDIR)/%.o, $(SRC))

all: $(NAME)

include ../common.mk

run: all
	@if [ "$(shell uname)" = "Darwin" ]; then \
		if [ -n "$(ARGS)" ]; then \
			./$(NAME) `jot -r $(ARGS) 1 100000 | tr '\n' ' '`; \
		else \
			./$(NAME) `jot -r 3000 1 100000 | tr '\n' ' '`; \
		fi \
	else \
		if [ -n "$(ARGS)" ]; then \
			./$(NAME) `shuf -i 1-100000 -n $(ARGS) | tr "\n" " "`; \
		else \
			./$(NAME) `shuf -i 1-100000 -n 3000 | tr "\n" " "`; \
		fi \
	fi

$(NAME): $(OBJ) $(INC)
	@$(CPP) -o "$@" $(CPPFLAGS) $(OBJ)
	@echo "$(GREEN)PmergeMe $(WHITE)Ready ✅ $(DEFAULT)"
