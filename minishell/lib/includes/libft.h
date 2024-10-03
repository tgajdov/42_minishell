/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:33:01 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/03 18:12:20 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <stdio.h>
# include <ctype.h>
# include <fcntl.h>
# include "../../include/minishell.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/* -------◊	FUNCTIONS TO MANIPULATE CHARACTERS	◊------- */
int		ft_isalnum(int i);
int		ft_isalpha(int i);
int		ft_isascii(int i);
int		ft_isdigit(int i);
int		ft_isprint(int i);
int		ft_tolower(int i);
int		ft_toupper(int i);

/* -------◊	FUNCTIONS TO MANIPULATE STRINGS	◊------- */
char	*ft_strchr(const char *s, int i);
char	*ft_strdup(const char *s);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *str, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
int		ft_countwords(char **tab);

/* -------◊		FUNCTIONS TO CONVERSION/STRINGS FOR INTEGERS	◊------- */
int		ft_atoi(const char *str);
char	*ft_itoa(int n);

/* -------◊		FUNCTIONS TO MANIPULATE MEMORY	◊------- */
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *s1, const void *s2, size_t n);
void	*ft_memset(void *b, int c, size_t len);

/* -------◊		FUNCTIONS TO MANIPULATE NUMBERS	◊------- */
int		ft_intlen(int n);

/* -------◊		FUNCTIONS TO MANIPULATE LISTS	◊------- */
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* -------◊		FUNCTIONS FILE DESCRIPTOR     ◊------- */
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/* -------◊	GNL	◊------- */
char	*get_next_line(int fd);

/* -------◊	PRINTF	◊------- */
int		ft_printf(const char *format, ...);
int		ft_printchar(char c, int len);
int		ft_printstr(char *str, int len);
int		ft_printnbr(int nb, int len);
int		ft_print_u_nbr(size_t nb, int len);
int		ft_print_ptr_add(size_t add, int len);
int		ft_print_xs(unsigned int add, int len);
int		ft_print_xl(unsigned int add, int len);

#endif
