/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 13:52:35 by idel-poz          #+#    #+#             */
/*   Updated: 2024/08/20 22:50:06 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_print_char(char c)
{
	write(FD_STDOUT, &c, 1);
	return (1);
}

unsigned int	ft_print_nbr(long n, int base, char *nbr_f)
{
	int		len;
	int		i;
	char	n_str[MAX_INT_LEN];

	len = 0;
	i = 0;
	if (n < 0)
	{
		len += ft_print_char('-');
		n = -n;
	}
	if (!n)
		return (ft_print_char('0'));
	while (n)
	{
		n_str[i++] = nbr_f[n % base];
		n /= base;
	}
	while (i--)
		len += ft_print_char(n_str[i]);
	return (len);
}

unsigned int	ft_print_addr(unsigned long n, int base, char *nbr_f)
{
	int		len;
	int		i;
	char	addr[MAX_LONG_LEN];

	len = ft_print_str("0x");
	i = 0;
	if (n == 0)
		return (len + ft_print_char('0'));
	while (n)
	{
		addr[i++] = nbr_f[n % base];
		n /= base;
	}
	while (i--)
		len += ft_print_char(addr[i]);
	return (len);
}

unsigned int	ft_print_str(char *str)
{
	unsigned int	len;

	len = 0;
	if (!str)
		str = "(null)";
	while (*str)
		len += ft_print_char(*str++);
	return (len);
}

int	ft_print_param(char format, va_list *va)
{
	if (format == 'c')
		return (ft_print_char(va_arg(*va, int)));
	if (format == 's')
		return (ft_print_str(va_arg(*va, void *)));
	if (format == 'd' || format == 'i')
		return (ft_print_nbr((long) va_arg(*va, int), 10, HEXL));
	if (format == 'u')
		return (ft_print_nbr((long) va_arg(*va, unsigned int), 10, HEXL));
	if (format == 'x')
		return (ft_print_nbr((long) va_arg(*va, unsigned int), 16, HEXL));
	if (format == 'X')
		return (ft_print_nbr((long) va_arg(*va, unsigned int), 16, HEXU));
	if (format == 'p')
		return (ft_print_addr((unsigned long) va_arg(*va, void *), 16, HEXL));
	return (ft_print_char(format));
}
