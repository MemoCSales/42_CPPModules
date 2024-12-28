NAME = PmergeMe

SRC = $(wildcard *.cpp)
INC = $(wildcard *.hpp)
OBJ = $(patsubst %.cpp, $(OBJDIR)/%.o, $(SRC))

all: $(NAME)

include ../common.mk

run: $(NAME)
	@./$(NAME)

$(NAME): $(OBJ) $(INC)
	$(CPP) -o "$@" $(CPPFLAGS) $(OBJ)
