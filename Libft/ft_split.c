/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 14:47:47 by idel-poz          #+#    #+#             */
/*   Updated: 2024/01/27 19:07:17 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "stdio.h"

static unsigned int	get_words_no(const char *s, char c);
void				iterate_and_init(
						const char *s,
						const char c,
						unsigned int worlds_qty,
						char **v);
static char			*init_and_copy_world(const char *s, unsigned int length);

// Splits the string s separating by every c found on it.
char	**ft_split(char const *s, char c)
{
	unsigned int	worlds_qty;
	char			**v;

	if (!s)
		return (NULL);
	worlds_qty = get_words_no(s, c);
	v = malloc(sizeof(char) * (worlds_qty + 1));
	if (!v)
		return (NULL);
	iterate_and_init(s, c, worlds_qty, v);
	v[worlds_qty] = NULL;
	// printf("RELLENAMOS LA POS %d: '%s'.\n", worlds_qty, v[worlds_qty]);
	return (v);
}

static unsigned int	get_words_no(const char *s, char c)
{
	unsigned int	i;

	if (!s)
		return (0);
	i = 1;
	while (*s)
	{
		if (*s == c && s[1])
			i++;
		s++;
	}
	return (i);
}

void	iterate_and_init(
	const char *s,
	const char c,
	unsigned int s_size,
	char **v)
{
	unsigned int	i;
	unsigned int	world_size;

	if (!s)
		return ;
	i = 0;
	world_size = 0;
	while (i < s_size)
	{
		if (*s == c || !*s)
		{
			v[i] = init_and_copy_world(s, world_size);
			if (!v[i])
				return ;
			// printf("RELLENAMOS LA POS %d: '%s'.\n", i, v[i]);
			i++;
			world_size = 0;
		}
		else
			world_size++;
		s++;
	}
}

static char	*init_and_copy_world(const char *s, unsigned int length)
{
	char			*v;
	unsigned int	i;

	if (!s)
		return (NULL);
	v = malloc(sizeof(char) * (length + 1));
	if (!v)
		return (NULL);
	s -= length;
	i = 0;
	while (i < length)
	{
		v[i] = s[i];
		i++;
	}
	v[i] = '\0';
	return (v);
}

/* #include "stdio.h"

int	main()
{
	char	*str = "Hola mundo!! munooo";
	char	sp = ' ';
	char	**res = ft_split(str, sp);
	printf("The string '%s' splitted by '%c' is:\n", str, sp);
	
	int i = 0;
	while (res[i]) {
		printf("\t%s\n", res[i]);
		i++;
	}
	return (0);
} */