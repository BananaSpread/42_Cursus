/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 13:42:22 by idel-poz          #+#    #+#             */
/*   Updated: 2024/01/14 20:23:15 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	c;

	i = 0;
	c = 0;
	while (i < len)
	{
		if (!needle[c])
			break ;
		if (haystack[i] != needle[c])
			c = 0;
		else
		{
			i++;
			c++;
		}
	}
	if (ft_strlen(needle) != c)
		return (NULL);
	return ((char *)&haystack[i]);
}
