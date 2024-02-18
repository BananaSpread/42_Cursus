/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 20:00:21 by idel-poz          #+#    #+#             */
/*   Updated: 2024/02/18 20:27:21 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include <unistd.h>

int main()
{
    char *format = "Esto es una prueba\tdel printf.\nnumero: %d\nstring: %s\nchar: %c\nhex: %x\nunsigned: %u\npuntero: %p\n";
    
    ft_printf(format, 42, "hola", 'c', 42, 42, &format);
    write(1, "\n", 1);
    printf(format, 42, "hola", 'c', 42, 42, &format);
    return (0);
}