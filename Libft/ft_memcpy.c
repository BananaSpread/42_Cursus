/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:34:01 by idel-poz          #+#    #+#             */
/*   Updated: 2024/01/28 12:41:50 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

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
