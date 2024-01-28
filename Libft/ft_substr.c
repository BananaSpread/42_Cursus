/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:16:07 by idel-poz          #+#    #+#             */
/*   Updated: 2024/01/28 17:41:48 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Extracts a substring from the string s, starting from start to len.
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	c;
	size_t	s_size;
	char	*v;

	s_size = ft_strlen(s);
	if (!s || start > s_size)
		return (ft_strdup(""));
	if (len > (s_size + start))
		len = (s_size + start);
	v = malloc(sizeof(char) * (len + 1));
	if (!v)
		return (NULL);
	i = start;
	c = 0;
	while (len-- && s[i])
	{
		v[c] = s[i];
		i++;
		c++;
	}
	v[c] = 0;
	return (v);
}
