/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:48:37 by idel-poz          #+#    #+#             */
/*   Updated: 2024/01/20 18:35:39 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	s_length;
	char	*v;

	i = 0;
	s_length = ft_strlen(s1);
	v = malloc((s_length * sizeof(char)) + 1);
	if (!v)
		return (NULL);
	while (s1[i])
	{
		v[i] = s1[i];
		i++;
	}
	v[i] = '\0';
	return (v);
}
