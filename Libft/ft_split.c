/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 14:47:47 by idel-poz          #+#    #+#             */
/*   Updated: 2024/02/17 18:02:28 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_words_no(const char *s, char c);
static size_t	get_word_length(const char *s, char c);
static char		**free_mem(char **v, size_t v_len);

// Splits the string s separating by every c found on it.
char	**ft_split(char const *s, char c)
{
	char	**v;
	size_t	len;
	size_t	i;
	size_t	chars_no;

	i = 0;
	chars_no = 0;
	len = get_words_no(s, c);
	v = (char **) malloc(sizeof(char *) * (len + 1));
	if (!v)
		return (NULL);
	while (i < len)
	{
		while (*s == c)
			s++;
		chars_no = get_word_length((const char *) s, c);
		v[i] = (char *) malloc(sizeof(char) * (chars_no + 1));
		if (!v[i])
			return (free_mem((char **) v, (i + 1)));
		ft_strlcpy(v[i], s, chars_no + 1);
		s = ft_strchr(s, (int) c);
		i++;
	}
	v[i] = 0;
	return (v);
}

static size_t	get_words_no(const char *s, char c)
{
	size_t	count;
	size_t	flag;

	count = 0;
	flag = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == c)
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static size_t	get_word_length(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	**free_mem(char **v, size_t v_len)
{
	size_t	i;

	i = 0;
	while (i < v_len)
		free((void *) v[i++]);
	free(v);
	return (NULL);
}

// #include "stdio.h"

// int	main()
// {
// 	char	*str = "      Hola       mundo!!  munooo     ";
// 	char	sp = ' ';
// 	char	**res = ft_split(str, sp);
// 	printf("The string '%s' splitted by '%c' is:\n", str, sp);

// 	int i = 0;
// 	while (res[i]) {
// 		printf("\t'%s'\n", res[i]);
// 		i++;
// 	}
// 	i = 0;
// 	while (res[i]) {
// 		free(res[i]);
// 		i++;
// 	}
// 	free(res);
// 	return (0);
// }