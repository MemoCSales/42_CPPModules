NAME = bureaucrat

SRC	= $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, $(OBJDIR)/%.o, $(SRC))

all: $(NAME)

include ../common.mk

run: $(NAME)
	@./$(NAME)

file:
	@files=$$(find . -name "*_shrubbery" -type f); \
	if [ -n "$$files" ]; then rm -r $$files; else echo "No Shrubbery files found"; fi

fclean: clean file

$(NAME): $(OBJ)
	$(CPP) -o "$@" $(CPPFLAGS) $(OBJ)
