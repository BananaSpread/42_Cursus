/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:16:25 by idel-poz          #+#    #+#             */
/*   Updated: 2024/01/28 13:23:35 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Concatenates src in dst up to specified size limit and returns
// the total length of the string tried to create.
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_l;
	size_t	dst_l;
	size_t	k;

	dst_l = ft_strlen(dst);
	src_l = ft_strlen(src);
	if (dstsize <= dst_l)
		return (dstsize + src_l);
	k = 0;
	if (dstsize > 0)
	{
		while (src[k] && k < (dstsize - dst_l - 1))
		{
			dst[dst_l + k] = src[k];
			k++;
		}
	}
	dst[dst_l + k] = '\0';
	return (dst_l + src_l);
}

// #include "stdio.h"
// #include "string.h"

// int	main()
// {
// 	char dest[10] = "Hello";
// 	char *src = " World";
// 	ft_strlcat(dest, src, sizeof(dest));
// 	// strlcat(dest, src, sizeof(dest));
// 	printf("RES: %s", dest);
// 	return (0);
// }