/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 20:00:21 by idel-poz          #+#    #+#             */
/*   Updated: 2024/02/25 15:17:44 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include <unistd.h>

int main()
{
    char *format = "Prueba del printf:\nchar:\t\t%c\nstring:\t\t%s\npuntero:\t%p\ndecimal d:\t%d\ninteger i:\t%i\nunsigned d:\t%u\nhex lo:\t\t%x\nhex up:\t\t%X\npercent:\t%%\n";

    // char c = 'c';
    // char *s = "hola";
    // float d = 42.42f;
    // int i = -42;
    // float u = -42.42f;
    // int x = -42;
    // int X = -42;

    printf("ft_printf:\t%d\n\n", ft_printf(format, 'c', "hola!!", &format, 42.42f, -42, -42.42f, -42, -42));
    printf("printf:\t\t%d\n", printf(format, 'c', "hola!!", &format, 42.42f, -42, -42.42f, -42, -42));

    // printf("ft_printf:\t%d\n\n", ft_printf(format, c, s, &format, d, i, u, x, X));
    // printf("printf:\t\t%d\n", printf(format, c, s, &format, d, i, u, x, X));
    return (0);
}