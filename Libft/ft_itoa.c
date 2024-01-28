/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 14:47:14 by idel-poz          #+#    #+#             */
/*   Updated: 2024/01/28 19:17:37 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

static	unsigned int	get_n_size(long n);
static	char			*get_itoa_str(long n, unsigned int n_size, int neg);

// Converts the integer argument n to an string and returns
// a pointer to the first element.
char	*ft_itoa(int n)
{
	long	n_val;
	int		neg;

	n_val = n;
	neg = 0;
	if (n < 0)
	{
		n_val *= -1;
		neg = 1;
	}
	return (get_itoa_str(n_val, get_n_size(n_val), neg));
}

static	unsigned	int	get_n_size(long n)
{
	unsigned int	s;

	if (n == 0)
		return (1);
	s = 0;
	while (n)
	{
		n /= 10;
		s++;
	}
	return (s);
}

static	char	*get_itoa_str(long n, unsigned int n_size, int neg)
{
	int		i;
	char	*v;

	v = malloc(sizeof(char) * (n_size + neg + 1));
	if (!v)
		return (NULL);
	v[n_size + neg] = '\0';
	i = ((int) n_size) + neg;
	if (neg == 1)
		v[0] = '-';
	while (i > neg)
	{
		v[i - 1] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	return (v);
}

// #include <limits.h>
// #include <stdio.h>

// void	print_result(int n) {
// 	printf("Entrada:\t%d\n", n);
// 	printf("ft:\t\t%s\n\n", ft_itoa(n));
// }

// int main() {
// 	print_result(0);
// 	print_result(889834);
// 	print_result(112233);
// 	print_result(-12739);
// 	print_result(INT_MAX);
// 	print_result(INT_MIN);

// 	return (0);
// }