# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgajdov <marvin@42lausanne.ch>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 13:15:09 by tgajdov           #+#    #+#              #
#    Updated: 2023/10/30 18:46:33 by tgajdov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# CFILES 	   = ft_strlen.c \
# 			 ft_memmove.c \
# 			 ft_memcpy.c \
# 			 ft_strlcpy.c \
# 			 ft_strlcat.c \
# 			 ft_intlen.c \
# 			 ft_isalpha.c \
# 			 ft_isdigit.c \
# 			 ft_isalnum.c \
# 			 ft_isascii.c \
# 			 ft_isprint.c \
# 			 ft_memset.c \
# 			 ft_bzero.c \
# 			 ft_toupper.c \
# 			 ft_tolower.c \
# 			 ft_strchr.c \
# 			 ft_strrchr.c \
# 			 ft_strncmp.c \
# 			 ft_memchr.c \
# 			 ft_memcmp.c \
# 			 ft_strnstr.c \
# 			 ft_atoi.c \
# 			 ft_calloc.c \
# 			 ft_strdup.c \
# 			 ft_substr.c \
# 			 ft_strjoin.c \
# 			 ft_strtrim.c \
# 			 ft_split.c \
# 			 ft_itoa.c \
# 			 ft_strmapi.c \
# 			 ft_striteri.c \
# 			 ft_putchar_fd.c \
# 			 ft_putstr_fd.c \
# 			 ft_putendl_fd.c \
# 			 ft_putnbr_fd.c \
# 			 ft_countwords.c \
# 			 ft_lstnew.c \
# 		 	 ft_lstadd_front.c \
# 		 	 ft_lstsize.c \
# 		 	 ft_lstlast.c \
# 			 ft_lstadd_back.c \
# 			 ft_lstdelone.c \
# 			 ft_lstclear.c \
# 			 ft_lstiter.c \
# 			 ft_lstmap.c \

CFILES = $(wildcard sources/*/*.c)

NAME = libft.a
CC = gcc
CCFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar -rcs

OFILES = $(CFILES:.c=.o)

# Colors
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
	@echo "$(GREEN) The Makefile of [LIBFT] has been compiled!$(DEF_COLOR)"

$(NAME):$(OFILES)
	$(AR) $@ $^
	
%.o: %.c
	$(CC) $(CCFLAGS) -o $@ -c $^

clean:
	$(RM) $(OFILES)
	@echo "$(BLUE) [LIBFT] Object files cleaned!$(DEF_COLOR)"

fclean: clean
	$(RM) $(NAME)
	@echo "$(BLUE) [LIBFT] Executable files cleaned!$(DEF_COLOR)"

re: fclean all
	@echo "$(BLUE) [LIBFT] Cleaned and rebuilt everything!$(DEF_COLOR)"

.PHONY: all, clean, fclean, re
