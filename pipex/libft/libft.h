/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:28:47 by idel-poz          #+#    #+#             */
/*   Updated: 2024/08/20 22:53:49 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# ifndef FD_STDOUT
#  define FD_STDOUT 1
# endif

# ifndef FD_STDERR
#  define FD_STDERR 2
# endif

# ifndef MAX_INT_LEN
#  define MAX_INT_LEN 12
# endif

# ifndef MAX_LONG_LEN
#  define MAX_LONG_LEN 22
# endif

# ifndef HEXL
#  define HEXL "0123456789abcdef"
# endif

# ifndef HEXU
#  define HEXU "0123456789ABCDEF"
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_stack
{
	char			*buf;
	struct s_stack	*next;
}	str_stack;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

// PRINTF
int				ft_printf(const char *format, ...);
unsigned int	ft_print_char(char c);
unsigned int	ft_print_nbr(long n, int base, char *nbr_f);
unsigned int	ft_print_addr(unsigned long n, int base, char *nbr_f);
unsigned int	ft_print_str(char *str);
int				ft_print_param(char format, va_list *va);

// GNL
char		*get_next_line(int fd);

void		stack_next_line(int fd, str_stack **stack);
int			str_has_line_break(str_stack *stack);
void		append_to_stack(str_stack **stack, char *buf);
int			get_line_len(str_stack *stack);
char		*copy_str_line(str_stack *stack, char *line);
char		*read_line(str_stack *stack);
void		clean_stack(str_stack **stack);
str_stack	*get_last_stack(str_stack *stack);
char		*get_remaining_buffer(str_stack **stack);
int			str_len(char *str);

#endif
