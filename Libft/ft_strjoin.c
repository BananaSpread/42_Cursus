/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:21:16 by idel-poz          #+#    #+#             */
/*   Updated: 2024/01/28 12:52:32 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Joins 2 strings (s1 and s2) and returns a pointer
// to the first element.
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i1;
	size_t	i2;
	char	*v;

	i1 = ft_strlen(s1);
	i2 = ft_strlen(s2);
	v = malloc((i1 + i2 + 1) * sizeof(char));
	if (!v)
		return (NULL);
	ft_memcpy(v, s1, i1);
	ft_memcpy(&v[i1], s2, i2);
	v[i1 + i2] = 0;
	return (v);
}

// #include "stdio.h"

// int	main()
// {
// 	char *s1 = "Hola ";
// 	char *s2 = "mundo1!";
// 	char *res = ft_strjoin(s1, s2);
// 	printf("RES: %s", res);
// 	return (0);
// }