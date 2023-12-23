/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:48:37 by idel-poz          #+#    #+#             */
/*   Updated: 2023/12/23 16:58:27 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	s_length;
	char	*v;

	i = 0;
	s_length = ft_strlen(s1);
	v = malloc(s_lenght * sizeof(char));
	while (s1[i])
	{
		v[i] = s1[i];
		i++;
	}
	return (v);
}
