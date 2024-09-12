NAME = diamondtrap

SRC			= $(wildcard *.cpp) \
				../ex00/ClapTrap.cpp \
				../ex01/ScavTrap.cpp \
				../ex02/FragTrap.cpp
OBJ			= $(patsubst %.cpp, $(OBJDIR)/%.o, $(SRC))

all: $(NAME)

include ../common.mk

run: $(NAME)
	@./$(NAME)

$(NAME): $(OBJ)
	$(CPP) -o "$@" $(CPPFLAGS) $(OBJ)

$(OBJDIR)/%.o: ../ex00/%.cpp ../ex01/%.cpp ../ex02/%.cpp
	@mkdir -p $(dir $@)
	@$(CPP) -o "$@" $(CPPFLAGS) "$<" -c