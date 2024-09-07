/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 13:42:22 by idel-poz          #+#    #+#             */
/*   Updated: 2024/02/17 15:12:15 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

// Search into the string haystack the substring needle up to len bytes and
// returns the first position if found. Returns NULL if not found.
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	nc;

	if (!*needle || haystack == needle)
		return ((char *) haystack);
	if (len == 0)
		return (NULL);
	i = 0;
	while (i < len && haystack[i])
	{
		nc = 0;
		while (i < len && haystack[i] == needle[nc] && needle[nc])
		{
			i++;
			nc++;
		}
		if (!needle[nc])
			return ((char *) &haystack[i - nc]);
		i = i - nc + 1;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>
// int	main()
// {
// 	char *str = "abcdefgh";
// 	char *ndl = "abc";
// 	int	len   = 2;
// 	// char *str = "aaxx";
// 	// char *ndl = "xx";
// 	// int	len   = 3;
// 	printf("Analizamos \"%s\" buscando \"%s\" hasta %d bytes\n", str, ndl, len);
// 	printf("\tFT: %s\n", ft_strnstr(str, ndl, len));
// 	printf("\tLB: %s\n", strnstr(str, ndl, len));
// 	return (0);
// }