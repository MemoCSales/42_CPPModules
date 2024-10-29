NAME = btc

SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, $(OBJDIR)/%.o, $(SRC))

all: $(NAME)

include ../common.mk

run: $(NAME)
	@./$(NAME) input.txt

$(NAME): $(OBJ)
	$(CPP) -o "$@" $(CPPFLAGS) $(OBJ)
