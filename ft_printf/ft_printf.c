/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 13:44:46 by idel-poz          #+#    #+#             */
/*   Updated: 2024/02/25 14:55:46 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_printf(const char *format, ...)
{
    int     len;
    va_list args;

    len = 0;
    va_start(args, format);
    while (*format)
    {
        if (*format == '%')
            len += ft_print_param(*(++format), &args);
        else
            len += ft_print_char(*format);
        format++;
    }
    va_end(args);
    return (len);
}



