/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:16:07 by idel-poz          #+#    #+#             */
/*   Updated: 2023/12/23 17:20:50 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	c;
	char	*v;

	i = start;
	c = 0;
	v = malloc(len * sizeof(char));
	while (s[i])
	{
		v[c] = s[i];
		i++;
		c++;
	}
	return (v);
}
