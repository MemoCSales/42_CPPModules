NAME = diamondtrap

SRC			= $(wildcard *.cpp)
OBJ			= $(patsubst %.cpp, $(OBJDIR)/%.o, $(SRC))


all: $(NAME)

include ../common.mk

run: $(NAME)
	@./$(NAME)

debug:
	@echo "SRC: $(SRC)"
	@echo "OBJ: $(OBJ)"
	@echo "OBJDIR: $(OBJDIR)"

$(NAME): $(OBJ)
	$(CPP) -o "$@" $(CPPFLAGS) $(OBJ)

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	@$(CPP) -o "$@" $(CPPFLAGS) "$<" -c

