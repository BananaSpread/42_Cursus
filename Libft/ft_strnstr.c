/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 13:42:22 by idel-poz          #+#    #+#             */
/*   Updated: 2024/01/28 15:52:58 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Search into the string haystack the substing needle up to len bytes and
// returns the first position if found. Returns NULL if not found.
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	c;

	if (!*haystack)
		return (NULL);
	if (!*needle || haystack == needle)
		return ((char *) haystack);
	i = 0;
	c = 0;
	while (len--)
	{
		if (!needle[c])
			return ((char *) &haystack[i - c]);
		if (haystack[i] == needle[c])
			c++;
		else
			c = 0;
		i++;
	}
	return (NULL);
}
