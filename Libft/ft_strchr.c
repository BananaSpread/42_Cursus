/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:51:15 by idel-poz          #+#    #+#             */
/*   Updated: 2024/02/04 18:36:41 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

// Finds the char c into the string s and returns a
// pointer to the memory block position
char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
		if (s[i++] == c)
			return ((char *) &s[i - 1]);
	if (s[i] == c)
		return ((char *) &s[i]);
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// int main() {
// 	char *str = "teste";
// 	char c = '\0';
// 	char *s1 = ft_strchr(str, c);
// 	char *s2 = strchr(str, c);

// 	printf("Buscamos la letra '%c' en '%s'\n", c, str);
// 	printf("\tFT: '%s'\n", s1);
// 	printf("\tLB: '%s'\n", s2);

// 	return (0);
// }