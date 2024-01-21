/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:24:44 by idel-poz          #+#    #+#             */
/*   Updated: 2024/01/21 15:29:02 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Converts the string argument str to an integer
int	ft_atoi(const char *str)
{
	long	v;
	int		m;

	m = 1;
	while (*str == ' ' || *str == '\t' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == '\n')
		str++;
	if (!ft_isdigit(*str) && *str != '+' && *str != '-')
		return (0);
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

/* 
#include <stdio.h>
#include <limits.h>

void	print_result(char *s) {
	int native_result = atoi(s);
	int ft_result = ft_atoi(s);
	int check = native_result == ft_result;

	printf("-> Entrada: %s", s);
	printf("\t\t");
	printf("Nativo: %d", native_result);
	printf("\t\t");
	printf("ft: %d", ft_result);
	printf("\t\t");
	printf("Check: %d", check);
	printf("\n");
}

int main() {
	char *s = "98273";
	print_result(s);
	s = "982 73";
	print_result(s);
	s = "  98273";
	print_result(s);
	s = "  -98273";
	print_result(s);
	s = "  +98273";
	print_result(s);
	s = "  ++98273";
	print_result(s);
	s = "  --98273";
	print_result(s);
	s = "++98273";
	print_result(s);
	s = "--98273";
	print_result(s);
	s = "f98273";
	print_result(s);
	s = "+98273";
	print_result(s);
	s = "t-98273";
	print_result(s);
	s = "t+98273";
	print_result(s);
	s = "+l98273";
	print_result(s);
	s = "-l98273";
	print_result(s);
	s = "98273   ";
	print_result(s);
	s = "l98273   ";
	print_result(s);
	s = "982h73";
	print_result(s);
	s = "l98-273";
	print_result(s);
	s = "982+73";
	print_result(s);
	s = "+42lyon";
	print_result(s);
	s = "2147483648";
	print_result(s);
	s = "-2147483647";
	print_result(s);
	
	s = " \t\v\n\r\f123";
	print_result(s);
	s = "\t 10";
	print_result(s);
	s = "\n 11";
	print_result(s);
	s = "\v 12";
	print_result(s);
	s = "\f 13";
	print_result(s);
	s = "\r 14";
	print_result(s);
	s = "12\r14";
	print_result(s);
	return (0);
}
  */