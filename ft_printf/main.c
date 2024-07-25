/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 20:00:21 by idel-poz          #+#    #+#             */
/*   Updated: 2024/05/19 19:33:14 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

void	test1()
{
	char *format = "Prueba del printf:\nchar c:\t\t%c\nstring s:\t%s\npuntero p:\t%p\ndecimal d:\t%d\ninteger i:\t%i\nunsigned u:\t%u\nhex lo x:\t%x\nhex up X:\t%X\npercent:\t%%\n";
	// format = NULL;

	char c = 'c';
	char *s = NULL;
	char *p = NULL;
	int d = -0;
	int i = -42;
	int u = -42;
	int x = 0x1A;
	int X = 0x1A;

	int res1 = ft_printf(format, c, s, p, d, i, u, x, X);
	printf("ft_printf:\t%d\n\n", res1);

	int res2 = printf(format, c, s, p, d, i, u, x, X);
	printf("printf:\t\t%d\n", res2);
}

void	test2()
{
	printf("TEST2:\n");
	printf("ft_printf:\t'%d'\n", ft_printf("\001\002\007\v\010\f\r\n"));
	printf("printf:\t\t'%d'\n", printf("\001\002\007\v\010\f\r\n"));
}

int main()
{
	test1();
    // test2();
	return (0);
}