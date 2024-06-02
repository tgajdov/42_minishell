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

CFILES 	   = $(wildcard *.c)


NAME = libft.a

CC = gcc

CCFLAGS = -Wall -Wextra -Werror

OFILES = $(CFILES:.c=.o)

BOFILES = $(BFILES:.c=.o)

RM = rm -rf

AR = ar -rcs

all: $(NAME)

$(NAME):$(OFILES)
	@echo "Making the archive: $@" 
	@$(AR) $@ $^
	@echo "$(NAME) done" 

bonus:$(OFILES) $(BOFILES)
	$(AR) $(NAME) $^
	
%.o: %.c
	@$(CC) $(CCFLAGS) -o $@ -c $^

clean:
	@echo "Cleaning up the Lib"
	@$(RM) $(OFILES)
	@$(RM) $(BOFILES)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, bonus
