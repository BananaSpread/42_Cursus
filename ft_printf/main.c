/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 20:00:21 by idel-poz          #+#    #+#             */
/*   Updated: 2024/02/25 21:14:54 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include <unistd.h>

int main()
{
    char *format = "Prueba del printf:\nchar c:\t\t%c\nstring s:\t%s\npuntero p:\t%p\ndecimal d:\t%d\ninteger i:\t%i\nunsigned u:\t%u\nhex lo x:\t%x\nhex up X:\t%X\npercent:\t%%\n";

    char c = 'c';
    char *s = "hola";
    int d = 42;
    int i = -42;
    int u = -42;
    int x = 42;
    int X = 42;

    int res1 = ft_printf(format, c, s, &format, d, i, u, x, X);
    printf("ft_printf:\t%d\n\n", res1);
    
    int res2 = printf(format, c, s, &format, d, i, u, x, X);
    printf("printf:\t\t%d\n", res2);
    
    return (0);
}