/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 14:48:17 by idel-poz          #+#    #+#             */
/*   Updated: 2024/01/14 20:20:47 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*v;

	i = 0;
	v = malloc((sizeof(char) * ft_strlen(s)) + 1);
	while (s[i])
	{
		v[i] = f(i, s[i]);
		i++;
	}
	v[i] = '\0';
	return (v);
}
