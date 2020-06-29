/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 15:04:06 by mvan-eng      #+#    #+#                 */
/*   Updated: 2020/04/14 16:01:02 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFF_SIZE 10000
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *src);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_atoi(const char *str);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_isprint(int c);
int					ft_isascii(int c);
void				ft_bzero(void *s, size_t n);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
size_t len);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_striter(char *s, void (*f)(char *));
void				ft_strclr(char *s);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
int					ft_strdcpy(char *dst, const char *src, char d, int i);
int					ft_strdcount(char const *s, char c);
int					ft_strdlen(const char *s, char c);
char				**ft_strsplit(char const *s, char c);
int					ft_digitc(int n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
char				*ft_itoa(int n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_isalnum(int c);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_lncount(char *str);
char				*ft_strndup(const char *src, size_t size);
int					get_next_line(const int fd, char **line);
int					ft_mapdel(void **map);
void				ft_putcmap(char **ar);
void				ft_putimap(int **ar);
int					ft_count_pointers(char **p);
int					ft_longlongc(long long n);
char				*ft_lltoa(long long n);
int					ft_natoi(const char *str, int n);
int					ft_datoi(const char *str, char d);
void				ft_putnbrlong(long long int nb);
int					ft_intlen(int n);
char				*ft_intos(char *strn, int intlen, int i, int n);
int					ft_llintlen(long long int n);
char				*ft_longtos(char *strn, int intlen, int i, long long int n);
char				*ft_nbrbase(long long l, int b);
void				ft_str_to_uppercase(char *s);
int					ft_charindex(const char *str, char c);
int					ft_ullintlen(unsigned long long n);
char				*ft_ulltoa(unsigned long long n);
char				*ft_fltoa(long double f, int prec);
int					ft_endcharcws(char *str, char c, char skip);
char				*ft_straddtofront(char *str, char *add);
char				*ft_straddtoend(char *str, char *add);
char				*ft_unbrbase(unsigned long long l, int b);
void				ft_arrdel(char **as);
size_t				ft_strlchr(char *s, char c, size_t len);

#endif
