/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:02:29 by idel-poz          #+#    #+#             */
/*   Updated: 2024/01/14 19:54:36 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*s;

	i = 0;
	s = b;
	while (i < len)
	{
		s[i] = c;
		i++;
	}
	return (b);
}
