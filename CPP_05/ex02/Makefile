NAME = bureaucrat

SRC	= $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, $(OBJDIR)/%.o, $(SRC))

all: $(NAME)

include ../common.mk

run: $(NAME)
	@./$(NAME)

file:
	@files=$$(find . -name "*_shrubbery" -type f); \
	rm -r "$$files";

fclean: clean file

$(NAME): $(OBJ)
	$(CPP) -o "$@" $(CPPFLAGS) $(OBJ)
