/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:51:15 by idel-poz          #+#    #+#             */
/*   Updated: 2024/02/17 13:59:59 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

// Finds the char c into the string s and returns a
// pointer to the memory block position
char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	uc;

	i = 0;
	uc = (unsigned char) c;
	while (s[i])
		if (s[i++] == uc)
			return ((char *) &s[i - 1]);
	if (s[i] == uc)
		return ((char *) &s[i]);
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// int main() {
// 	char *str = "teste";
// 	char c = 'e';
// 	char *s1 = ft_strchr(str, c);
// 	char *s2 = strchr(str, c);

// 	printf("Buscamos la letra '%c' en '%s'\n", c, str);
// 	printf("\tFT: '%s'\n", s1);
// 	printf("\tLB: '%s'\n", s2);

// 	return (0);
// }