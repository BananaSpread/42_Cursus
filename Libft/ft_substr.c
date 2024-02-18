/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:16:07 by idel-poz          #+#    #+#             */
/*   Updated: 2024/02/17 18:39:03 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Extracts a substring from the string s, starting from start to len.
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*v;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > (s_len - start))
		len = (s_len - start);
	v = malloc(sizeof(char) * (len + 1));
	if (!v)
		return (NULL);
	ft_memcpy(v, s + start, len);
	v[len] = 0;
	return (v);
}
