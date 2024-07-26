NAME = example

CPP			= g++
CPPFLAGS	= -std=c++98
CPPFLAGS	+= -Wall -Wextra -Werror
CPPFLAGS	+= -g

SRC 		= $(wildcard *.cpp)

OBJDIR		= .obj
OBJ			= $(patsubst %.cpp, $(OBJDIR)/%.o, $(SRC))

all: $(NAME)

run: $(NAME)
	./$(NAME)

$(NAME): $(OBJ)
	$(CPP) -o "$@" $(CPPFLAGS) $(OBJ)

compile: $(OBJDIR)/$(FILE).o
	$(CPP) -o $(FILE) $(CPPFLAGS) $(OBJDIR)/$(FILE).o

$(OBJDIR)/$(FILE).o: $(FILE).cpp
	@mkdir -p $(OBJDIR)
	@$(CPP) $(CPPFLAGS) -c $(FILE).cpp -o $(OBJDIR)/$(FILE).o

clean:
	$(RM) $(OBJ)
	-@rmdir $(OBJDIR) 2>/dev/null || true

fclean: clean
	$(RM) $(NAME) $(FILE)

re: fclean
	$(MAKE) $(NAME)

.PHONY: all clean fclean re