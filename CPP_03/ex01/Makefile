NAME = claptrap

SRC			= $(wildcard *.cpp) \
				../ex00/ClapTrap.cpp
OBJ			= $(patsubst %.cpp, $(OBJDIR)/%.o, $(SRC))

all: $(NAME)

include ../common.mk

run: $(NAME)
	@./$(NAME)

$(NAME): $(OBJ)
	$(CPP) -o "$@" $(CPPFLAGS) $(OBJ)

$(OBJDIR)/%.o: ../ex00/%.cpp
	@mkdir -p $(dir $@)
	@$(CPP) -o "$@" $(CPPFLAGS) "$<" -c
