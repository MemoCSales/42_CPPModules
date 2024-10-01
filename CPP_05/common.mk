# Contains common build rules and settings that are shared
# Compiler and flags
CPP			 = c++
CPPFLAGS	 = -std=c++98
CPPFLAGS	+= -Wall -Wextra -Werror -Wshadow -pedantic
CPPFLAGS	+= -g

# Directories
OBJDIR		= .obj

# Common rules
$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(CPP) -o "$@" $(CPPFLAGS) "$<" -c

clean:
	$(RM) $(OBJ)
	-@rmdir $(OBJDIR) 2>/dev/null || true

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) $(NAME)

val: 
	valgrind --leak-check=full ./$(NAME)

.PHONY: all clean fclean re val