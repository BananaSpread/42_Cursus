/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:24:44 by idel-poz          #+#    #+#             */
/*   Updated: 2024/02/17 13:38:57 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Converts the string argument str to an integer
int	ft_atoi(const char *str)
{
	long	v;
	int		m;

	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (!ft_isdigit(*str) && *str != '+' && *str != '-')
		return (0);
	v = 0;
	m = 1;
	if (*str == '-')
	{
		m = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (ft_isdigit(*str))
			v = (v * 10) + (*str - '0');
		else
			break ;
		str++;
	}
	return ((int)(v * m));
}

// #include <stdio.h>
// #include <limits.h>

// void	print_result(char *s) {
// 	int native_result = atoi(s);
// 	int ft_result = ft_atoi(s);
// 	int check = native_result == ft_result;

// 	printf("-> Entrada: %s", s);
// 	printf("\t\t");
// 	printf("Nativo: %d", native_result);
// 	printf("\t\t");
// 	printf("ft: %d", ft_result);
// 	printf("\t\t");
// 	printf("Check: %d", check);
// 	printf("\n");
// }

// int main() {
// 	print_result("98273");
// 	print_result("982 73");
// 	print_result("  98273");
// 	print_result("  -98273");
// 	print_result("  +98273");
// 	print_result("  ++98273");
// 	print_result("  --98273");
// 	print_result("++98273");
// 	print_result("--98273");
// 	print_result("f98273");
// 	print_result("+98273");
// 	print_result("t-98273");
// 	print_result("t+98273");
// 	print_result("+l98273");
// 	print_result("-l98273");
// 	print_result("98273   ");
// 	print_result("l98273   ");
// 	print_result("982h73");
// 	print_result("l98-273");
// 	print_result("982+73");
// 	print_result("+42lyon");
// 	print_result("2147483648");
// 	print_result("-2147483647");

// 	print_result(" \t\v\n\r\f123");
// 	print_result("\t 10");
// 	print_result("\n 11");
// 	print_result("\v 12");
// 	print_result("\f 13");
// 	print_result("\r 14");
// 	print_result("12\r14");

// 	print_result("0");
// 	printf("%i\n", ft_atoi("0"));
// 	printf("%i\n", ft_atoi("0"));
// 	print_result("3+1");
// 	print_result("2-1");
// 	print_result("1- +42");

// 	return (0);
// }