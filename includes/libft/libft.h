/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:00:59 by nburchha          #+#    #+#             */
/*   Updated: 2023/11/30 15:18:37 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>

# ifndef S_NODE
#  define S_NODE

typedef struct s_node
{
	void			*content;
	int				index;
	struct s_node	*next;
}					t_node;
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

int			ft_isalnum(char c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_isdigit(int c);
void		*ft_memset(void *b, int c, size_t len);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
int			ft_strlen(const char *str);
int			ft_tolower(int c);
int			ft_toupper(int c);
char		*ft_strchr(const char *s, int c);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
int			ft_atoi(const char *str);
int			ft_atoi_hex(const char *str);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		**ft_split(char const *s, char c);
void		*ft_memchr(const void *s, int c, size_t n);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
t_node		*ft_lstnew(void *content);
void		ft_lstadd_front(t_node **lst, t_node *new);
int			ft_lstsize(t_node *lst);
t_node		*ft_lstlast(t_node *lst);
void		ft_lstadd_back(t_node **lst, t_node *new);
void		ft_lstdelone(t_node *lst, void (*del)(void *));
void		ft_lstclear(t_node **lst, void (*del)(void *));
void		ft_lstiter(t_node *lst, void (*f)(void *));
t_node		*ft_lstmap(t_node *lst, void *(*f)(void *), void (*del)(void *));
int			ft_count_digits(unsigned int n);

char		*get_next_line(int fd);
int			ft_strchr2(const char *s, int c);
char		*ft_strjoin_free_s1(char *s1, char *s2);
char		*ft_substr2(char *s, size_t len);
int			ft_strlen2(char *str);
void		*ft_calloc2(size_t count, size_t size);

#endif