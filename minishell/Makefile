.PHONY: all clean fclean re testleaks test lib clean cleanlib

NAME = minishell
CC = gcc
CCFLAGS = -Wall -Werror -Wextra
DBGFLAG = -g3
LIBFLAGS = -L$(LIB_DIR) -l$(LIB_NAME)
LEAKS = leaks -atExit --
LEAKSLINUX = valgrind --leak-check=full
LEAKSLINUXDEEP = $(LEAKSLINUX) --show-leak-kinds=all
DATARACE = -fsanitize=thread

RM = rm -rf
MKDIR = mkdir -p

LIB_DIR = lib
SRC_DIR = src/*/
OBJ_DIR = bin
BIN_DIR = bin

LIB_NAME = ft
SRCS = src/builtin/*.c src/utils/*.c
#SRCS = $(wildcard ${SRC_DIR}*.c)
OBJS = $(SRCS:${SRC_DIR}/%.c=${OBJ_DIR}/%.o)

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

all: $(NAME)

$(NAME): $(LIB_DIR) $(OBJS)
	@echo "Creating ./$@"
	@$(CC) $(CCFLAGS) $(OBJS) $(LIBFLAGS) -o $(NAME)
	@echo "$(GREEN)$(NAME) has been compied!\n$(DEF_COLOR)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "Creating ./$@"
	$(MKDIR) $(BIN_DIR)
	$(CC) $(CCFLAGS) -c $< -o $@

$(LIB_DIR):
	@make -C $@

test:

testleaks:
	@$(LEAKSLINUX) ./$(NAME)

clean:
	@echo "Cleaning up $(NAME)"
	@$(RM) $(OBJ_DIR)
	@echo "$(BLUE)$(NAME) Object files cleaned!$(DEF_COLOR)"

cleanlib:
	@make fclean -C $(LIB_DIR)

fclean: clean cleanlib
	@$(RM) $(NAME)
	@echo "$(BLUE)$(NAME) Executable files cleaned!$(DEF_COLOR)\n"

re: fclean all
	@echo "$(BLUE)$(NAME) has been cleaned and re-compiled.$(DEF_COLOR)"
