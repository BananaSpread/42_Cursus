/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 14:47:14 by idel-poz          #+#    #+#             */
/*   Updated: 2024/01/21 15:57:57 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

char	static	*reverse(char *s, int size);

// Converts the integer argument n to an string and returns
// a pointer to the first element.
char	*ft_itoa(int n)
{
	char	*v;
	size_t	i;
	int		aux;

	v = malloc(sizeof(char) * 12);
	if (!v)
		return (NULL);
	i = 0;
	aux = n;
	while (aux > 0)
	{
		v[i] = aux % 10;
		aux /= 10;
		i++;
	}
	if (n < 0)
		v[i++] = '-';
	v[i++] = '\0';
	return (reverse(v, i));
}

char	static	*reverse(char *s, int size)
{
	char	c;
	size_t	i;

	i = 0;
	while (i < (size_t)size / 2)
	{
		c = s[i];
		s[i] = s[size - i - 1];
		s[size - i - 1] = c;
		i++;
	}
	return (s);
}

#include <limits.h>
#include <stdio.h>

void	print_result(int n) {
	char *native_result = itoa(n);
	char *ft_result = ft_itoa(n);

	printf("-> Entrada: %d", n);
	printf("\t\t");
	printf("Nativo: %s", native_result);
	printf("\t\t");
	printf("ft: %s", ft_result);
	printf("\n");
}

int main() {
	int n = 0;
	print_result(n);
	n = 45;
	print_result(n);
	n = 889834;
	print_result(n);
	n = -0;
	print_result(n);
	n = -6;
	print_result(n);
	n = -12739;
	print_result(n);
	n = INT_MAX;
	print_result(n);
	n = INT_MIN;
	print_result(n);

	return (0);
}