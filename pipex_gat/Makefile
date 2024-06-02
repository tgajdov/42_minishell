.PHONY: all clean fclean re lib

SRCS = $(wildcard *.c)
OBJS = $(SRCS:%.c=%.o)
NAME = pipex
CC = gcc
CCFLAGS = -Wall -Wextra -Werror
LIB_DIR = ./Libft
LIB_NAME = ft
RM = rm -rf

all: lib $(NAME)

#-L./Libft	: indique ou se trv la lib qu'il faut ajouter
#-lft		: indique le nom de la lib, mais sans le préfixe lib-

$(NAME): $(OBJS)
	@echo "Creating ./$@" 
	@${CC} ${CCFLAGS} -L$(LIB_DIR) -l$(LIB_NAME) $^ -o $@
	@echo "./$@ done" 

#-I	: indique ou se trv le .h de la lib
#alternative : noter dans le header local

%.o: %.c
	@echo "Creating $@" 
	@${CC} ${CCFLAGS} -c $<

#-C : permets de changer de dir avant d'exec la cmd

lib:
	@echo "Creating $@" 
	@make -C Libft/

clean:
	@echo "Cleaning up Pipex "
	@${RM} *.o

cleanlib:
	@make fclean -C Libft/

fclean: clean cleanlib
	@${RM} ${NAME}

re: fclean all