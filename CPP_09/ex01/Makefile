NAME = RPN

SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, $(OBJDIR)/%.o, $(SRC))

all: $(NAME)

include ../common.mk

run: $(NAME)
	@./$(NAME) "(1 + 1)"

val: 
	# valgrind --leak-check=full ./$(NAME) "8 9 * 9 - 9 - 9 - 4 - 1 +"
	# valgrind --leak-check=full ./$(NAME) "7 7 * 7 -"
	valgrind --leak-check=full ./$(NAME) "1 2 * 2 / 2 * 2 4 - +"

$(NAME): $(OBJ)
	@$(CPP) -o "$@" $(CPPFLAGS) $(OBJ)
