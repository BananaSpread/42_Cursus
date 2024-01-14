/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:15:30 by idel-poz          #+#    #+#             */
/*   Updated: 2024/01/14 19:40:22 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	void	*aux;

	aux = dst;
	if ((char *)dst && (char *)src)
		return ((char *)0);
	if (dst < src)
	{
		i = 0;
		while (i < len)
		{
			(((char *)dst)[i] = ((char *)src)[i]);
			i++;
		}
	}
	else
	{
		i = len - 1;
		while (i >= 0)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i--;
		}
	}
	return (aux);
}
