/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 13:56:49 by idel-poz          #+#    #+#             */
/*   Updated: 2024/03/03 16:24:37 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Finds the char c into the string s and returns a
// pointer to the memory block position
char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	uc;

	i = 0;
	uc = (unsigned char) c;
	while (s[i])
		if (s[i++] == uc)
			return ((char *) &s[i - 1]);
	if (s[i] == uc)
		return ((char *) &s[i]);
	return (NULL);
}

// Joins 2 strings (s1 and s2) and returns a pointer
// to the first element.
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i1;
	size_t	i2;
	char	*v;

	if (!s1 || !s2)
		return (NULL);
	i1 = ft_strlen(s1);
	i2 = ft_strlen(s2);
	v = malloc((i1 + i2 + 1) * sizeof(char));
	if (!v)
		return (NULL);
	ft_memcpy(v, s1, i1);
	ft_memcpy(&v[i1], s2, i2);
	v[i1 + i2] = 0;
	return (v);
}

// Returns the length of the string s
size_t	ft_strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (s[l])
		l++;
	return (l);
}

// Copies n bytes from src to dst.
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (!dst && src == 0)
		return (NULL);
	d = (unsigned char *) dst;
	s = (unsigned char *) src;
	while (n--)
	{
		*d = *s;
		d++;
		s++;
	}
	return (dst);
}