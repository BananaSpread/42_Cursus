/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 20:08:02 by idel-poz          #+#    #+#             */
/*   Updated: 2024/01/14 19:23:16 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	c1;
	char	c2;

	i = 0;
	while (i < n)
	{
		c1 = (char)&s1[i];
		c2 = (char)&s2[i];
		i++;
		if (!c1 || !c2)
			continue ;
		if (c1 < c2)
			return (-1);
		if (c1 > c2)
			return (1);
	}
	return (0);
}
