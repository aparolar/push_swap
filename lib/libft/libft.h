/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:48:46 by aparolar          #+#    #+#             */
/*   Updated: 2021/12/22 11:59:20 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <unistd.h>

/*
**  Defines
*/

# define GNL_BUFFER_SIZE 1024

/*
**  Simple List
*/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/*
**  Extended List
*/

typedef struct s_extlst
{
	void			*content;
	size_t			*count;
	struct s_extlst	*begin;
	struct s_extlst	*end;
	struct s_extlst	*before;
	struct s_extlst	*after;
}					t_extlst;

/*
**  Part 1
*/

void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memccpy(void *dst, const void *src, int c, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memmove(void *dst, void *src, size_t len);
size_t		ft_strlen(const char *s);
int			ft_isalpha(int c);
int			ft_tolower(int c);
int			ft_toupper(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_isdigit(int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
void		*ft_calloc(size_t count, size_t size);
int			ft_atoi(const char *str);
char		*ft_strdup(const char *s1);

/*
**  Part 2
*/

char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
char		*ft_itoa(int n);
void		ft_putnbr_fd(int n, int fd);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		**ft_split(char const *s, char c);

/*
**  Bonus
*/

t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **alst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void*));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*));

/*
**  Especial
*/

int			ft_intlen(int n);
int			ft_longlen(long n);
long		ft_atol(const char *str);
char		*ft_ltoa(long n);

/*
**   strings
*/

char		*ft_strrem(const char *s, size_t start, size_t len);
char		*ft_strcat(const char *s1, const char *s2);
int			ft_is_valid_aint(char *str);

/*
**  Files
*/

int			get_next_line(int fd, char **line);

/*
**  Print in screen
*/

int			ft_putchar(char c);
int			ft_putstr(char *str);
int			ft_iputnbr(int n);

/*
**  Especial lists
*/

t_extlst	*ft_extlstnew(void *content);
t_extlst	*ft_extlstclone(t_extlst *lst);
t_extlst	*ft_extlstaddbefore(t_extlst *lst, void *content);
t_extlst	*ft_extlstaddafter(t_extlst *lst, void *content);
void		ft_extlstdelone(t_extlst *lst, void (*del)(void*));
void		ft_extlstclear(t_extlst *lst, void (*del)(void*));

#endif
