# Contains common build rules and settings that are shared
# Compiler and flags
CPP			 = c++
CPPFLAGS	 = -std=c++98
CPPFLAGS	+= -Wall -Wextra -Werror -Wshadow #-pedantic
# CPPFLAGS	+= -fsanitize=address
CPPFLAGS	+= -g

# Directories
OBJDIR		= .obj

# Colors
GREEN   = \033[1;32m
WHITE   = \033[1;37m
YELLOW  = \033[1;33m
DEFAULT = \033[0m

# Common rules
$(OBJDIR)/%.o: %.cpp $(INC)
	@mkdir -p $(dir $@)
	@echo "$(GREEN)Compiling... $(WHITE)$<$(DEFAULT)"
	@$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@echo "$(YELLOW)Removing dependencies... $(WHITE)$(OBJ)$(DEFAULT)"
	-@rmdir $(OBJDIR) 2>/dev/null || true

fclean: clean
	@$(RM) $(NAME)
	@echo "$(YELLOW)Removing executable... $(WHITE)$(NAME)$(DEFAULT)"

re: fclean
	$(MAKE) $(NAME)

# val: 
# 	valgrind --leak-check=full ./$(NAME)

.PHONY: all clean fclean re val