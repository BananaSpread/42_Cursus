/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:34:01 by idel-poz          #+#    #+#             */
/*   Updated: 2024/01/20 19:35:07 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*d;
	char	*s;

	if (!dst && src == 0)
		return (NULL);
	d = (char *)dst;
	s = (char *)src;
	while (n > 0)
	{
		*d = *s;
		d++;
		s++;
		n--;
	}
	return (dst);
}
