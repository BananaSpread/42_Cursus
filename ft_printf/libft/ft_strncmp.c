/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:01:01 by idel-poz          #+#    #+#             */
/*   Updated: 2024/01/28 14:05:54 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

// Compares the strings s1 with s2 up to n bytes
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!n)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < (n - 1))
		i++;
	return (((unsigned char) s1[i]) - ((unsigned char) s2[i]));
}
