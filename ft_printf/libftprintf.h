/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 13:38:55 by idel-poz          #+#    #+#             */
/*   Updated: 2024/02/25 14:29:33 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft/libft.h"
# include "stdarg.h"

# define FD_STDOUT 1
# define FD_STDERR 2
# define MAX_INT_LEN 12
# define MAX_LONG_LEN 22
# define HEXL "0123456789abcdef"
# define HEXU "0123456789ABCDEF"

int             ft_printf(const char *format, ...);
unsigned int    ft_print_char(char c);
unsigned int    ft_print_nbr(long n, int base, char *nbr_f);
unsigned int    ft_print_addr(unsigned long n, int base, char *nbr_f);
unsigned int    ft_print_str(char *str);
int             ft_print_param(char format, va_list *va);

#endif