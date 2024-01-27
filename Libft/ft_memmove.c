/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:15:30 by idel-poz          #+#    #+#             */
/*   Updated: 2024/01/27 13:18:07 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

// Copies the first len bytes from src to dst. It controls that
// memory blocks do not overlap.
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*dest_ptr;

	dest_ptr = dst;
	if ((!dst && !src) || dst == src)
		return (dst);
	if (dst > src)
		while (len--)
			((char *) dst)[len] = ((char *) src)[len];
	else
		while (len--)
			*(char *) dst++ = *(char *) src++;
	return (dest_ptr);
}
