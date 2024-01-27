/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 14:47:47 by idel-poz          #+#    #+#             */
/*   Updated: 2024/01/27 14:26:29 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// Splits the string s separated by every c found on it.
char	**ft_split(char const *s, char c)
{
	size_t	vx;
	size_t	vy;
	char	**v;

	if (!*s)
		return (NULL);
	vx = 0;
	vy = 0;
	v = malloc(sizeof(char) * 1024);
	while (*s)
	{
		if (!v[vx])
			v[vx] = malloc(sizeof(char) * 128);
		if (*s == c)
		{
			v[vx++][vy] = '\0';
			vy = 0;
		}
		else
			v[vx][vy++] = *s;
		s++;
	}
	v[vx][vy] = '\0';
	free(v);
	return (v);
}
