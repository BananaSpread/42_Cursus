/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:01:01 by idel-poz          #+#    #+#             */
/*   Updated: 2024/01/27 12:11:52 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	char	c1;
	char	c2;

	i = 0;
	while (i <= n)
	{
		c1 = s1[i];
		c2 = s2[i];
		i++;
		if (!c1 || !c2)
			continue ;
		if (c1 > c2)
			return (-1);
		if (c1 < c2)
			return (1);
	}
	return (0);
}
