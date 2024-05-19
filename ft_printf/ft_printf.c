/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 13:44:46 by idel-poz          #+#    #+#             */
/*   Updated: 2024/05/19 19:23:29 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	args;

	if (!format)
		return (-1);
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
