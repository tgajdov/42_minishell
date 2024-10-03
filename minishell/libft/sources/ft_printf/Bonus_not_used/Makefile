# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgajdov <marvin@42lausanne.ch>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/29 14:23:12 by tgajdov           #+#    #+#              #
#    Updated: 2023/11/05 14:45:24 by tgajdov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES = ft_printf.c \
		 ft_printchar.c \
		 ft_printstr.c \
		 ft_printnbr.c \
		 ft_print_u_nbr.c \
		 ft_print_ptr_add.c \
		 ft_print_xs.c \
		 ft_print_xl.c \
		 ft_what_to_print.c 

BFILES = ft_print_xs_xl.c \
		 ft_printplus.c \
		 ft_printspace.c \

NAME = libftprintf.a

CC = gcc

CCFLAGS = -Wall -Wextra -Werror

OFILES = $(CFILES:.c=.o)

BOFILES = $(BFILES:.c=.o)

RM = rm -f

AR = ar -rcs

all: $(NAME)

$(NAME):$(OFILES)
	$(AR) $@ $^

bonus:$(OFILES) $(BOFILES)
	$(AR) $(NAME) $^

%.o: %.c
	$(CC) $(CCFLAGS) -o $@ -c $^ 

clean:
	$(RM) $(OFILES)
	$(RM) $(BOFILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
