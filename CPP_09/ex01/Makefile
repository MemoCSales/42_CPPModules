NAME = RPN

SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, $(OBJDIR)/%.o, $(SRC))

all: $(NAME)

include ../common.mk

run: $(NAME)
	@./$(NAME) "(1 + 1)"

val: 
	valgrind --leak-check=full ./$(NAME) "8 9 * 9 - 9 - 9 - 4 - 1 +"

$(NAME): $(OBJ)
	$(CPP) -o "$@" $(CPPFLAGS) $(OBJ)
