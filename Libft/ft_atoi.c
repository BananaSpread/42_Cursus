/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:24:44 by idel-poz          #+#    #+#             */
/*   Updated: 2024/01/20 20:33:22 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include <stdio.h>

int	ft_atoi(const char *str)
{
	size_t	i;
	int		v;
	int		m;
	char	c;

	i = 0;
	m = 1;
	v = 0;
	while (str[i])
	{
		c = str[i];
		if (c >= '0' && c <= '9')
			v = (v * 10) + (c - '0');
		else if (c == '-')
			m = -1;
		else if (c == ' ')
			continue ;
		else
			break ;
		i++;
	}
	v *= m;
	return (v);
}

int main()
{
	char *s = "982 7342";

	printf("Str: %s, \n", s);
	printf("resultado nativo %d\n", atoi(s));
	printf("resultado ft %d\n", ft_atoi(s));
	printf("comprobacion %d\n", ft_atoi(s) - atoi(s));
	return (0);
}
