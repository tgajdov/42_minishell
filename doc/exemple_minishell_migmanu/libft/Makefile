# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: johnavar <johnavar@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/02 16:45:08 by johnavar          #+#    #+#              #
#    Updated: 2023/11/21 13:05:27 by sebasnadu        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS
DEFAULT = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

NAME	= libft.a

DIR_SRCS	= src
DIR_OBJS	= obj
SUBDIRS		= is to mem str put lst printf gnl mtx

SRCS_DIRS	= $(foreach dir, $(SUBDIRS), $(DIR_SRCS)/$(dir))
OBJS_DIRS	= $(foreach dir, $(SUBDIRS), $(DIR_OBJS)/$(dir))
SRCS		= $(foreach dir, $(SRCS_DIRS), $(wildcard $(dir)/*.c))
OBJS		= $(subst $(DIR_SRCS), $(DIR_OBJS), $(SRCS:.c=.o))

INCLUDES	= includes

CC			= cc
FLAGS		= -Wall -Wextra -Werror
RM			= rm -rf
PRINTF		= printf

LIBC		= ar -rcs

# Progress vars
SRC_COUNT_TOT := $(shell expr $(shell echo -n $(SRCS) | wc -w) - $(shell ls -l $(OBJS) 2>&1 | grep ".o" | wc -l))
ifeq ($(shell test $(SRC_COUNT_TOT) -lt 0; echo $$?),1)
	SRC_COUNT_TOT := $(shell expr $(shell echo -n $(SRCS) | wc -w) - 1)
endif
SRC_COUNT := 0
SRC_PCT = $(shell expr 100 \* $(SRC_COUNT) / $(SRC_COUNT_TOT))

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c
	@mkdir -p $(DIR_OBJS) $(OBJS_DIRS)
	@$(eval SRC_COUNT = $(shell expr $(SRC_COUNT) + 1))
	@$(PRINTF) "\r%100s\r[ %d/%d (%d%%) ] Compiling $(BLUE)$<$(DEFAULT)..." "" $(SRC_COUNT) $(SRC_COUNT_TOT) $(SRC_PCT)
	@$(CC) $(FLAGS) -I$(INCLUDES) -c $< -o $@

all: 		$(NAME)

$(NAME):	$(OBJS)
	@$(LIBC) $(NAME) $(OBJS)
	@ranlib $(NAME)
	@$(PRINTF) "\r%100s\r$(GREEN)$(NAME) is up to date!$(DEFAULT)\n"

clean:
	@$(PRINTF) "$(CYAN)Cleaning up object files in libft...$(DEFAULT)\n"
	@$(RM) $(DIR_OBJS)

fclean:		clean
	@$(RM) $(NAME)
	@$(PRINTF) "$(CYAN)Removed $(NAME)$(DEFAULT)\n"

re:			fclean all

norminette:
	@$(PRINTF) "$(CYAN)\nChecking norm for libft...$(DEFAULT)\n"
	@norminette -R CheckForbiddenSourceHeader $(SRCS) $(INCLUDES)

.PHONY:		all clean fclean re norminette
