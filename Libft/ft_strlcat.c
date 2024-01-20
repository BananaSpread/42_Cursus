/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:16:25 by idel-poz          #+#    #+#             */
/*   Updated: 2024/01/20 16:59:12 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	k;

	j = ft_strlen(dst);
	i = ft_strlen(src);
	if (dstsize <= j)
		return (dstsize + i);
	k = 0;
	if (dstsize > 0)
	{
		while (src[k] && k < dstsize - j - 1)
		{
			dst[j + k] = src[k];
			k++;
		}
	}
	dst[j + k] = '\0';
	return (j + i);
}
