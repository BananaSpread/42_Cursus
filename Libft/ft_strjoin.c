/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:21:16 by idel-poz          #+#    #+#             */
/*   Updated: 2024/01/14 20:07:59 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i1;
	size_t	i2;
	char	*v;

	i1 = ft_strlen(s1);
	i2 = ft_strlen(s2);
	v = malloc((i1 + i2) * sizeof(char));
	ft_memcpy(v, s1, i1);
	ft_memcpy(&v[i1 - 1], s2, i2);
	return (v);
}
