NAME = diamondtrap

SRC			= $(wildcard *.cpp) \
				../ex00/ClapTrap.cpp \
				../ex01/ScavTrap.cpp \
				../ex02/FragTrap.cpp
OBJ			= $(patsubst %.cpp, $(OBJDIR)/%.o, $(notdir $(SRC)))

all: $(NAME)

include ../common.mk

run: $(NAME)
	@./$(NAME)

$(NAME): $(OBJ)
	$(CPP) -o "$@" $(CPPFLAGS) $(OBJ)

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	@$(CPP) -o "$@" $(CPPFLAGS) "$<" -c

$(OBJDIR)/%.o: ../ex00/%.cpp
	@mkdir -p $(OBJDIR)
	@$(CPP) -o "$@" $(CPPFLAGS) "$<" -c

$(OBJDIR)/%.o: ../ex01/%.cpp
	@mkdir -p $(OBJDIR)
	@$(CPP) -o "$@" $(CPPFLAGS) "$<" -c

$(OBJDIR)/%.o: ../ex02/%.cpp
	@mkdir -p $(OBJDIR)
	@$(CPP) -o "$@" $(CPPFLAGS) "$<" -c
