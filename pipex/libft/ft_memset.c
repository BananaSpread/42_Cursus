/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:02:29 by idel-poz          #+#    #+#             */
/*   Updated: 2024/02/17 15:35:12 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

// Fills in the first len bytes of b pointer with the value
// of c and returns a pointer to the filled memory block.
void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((char *) b)[i] = c;
		i++;
	}
	return (b);
}

// #include <stdio.h>
// #include <string.h>

// int main(void)
// {
// 	// char str[50] = "Hello World!";
// 	// ft_memset(str, 'a', 5);
// 	// printf("%s\n", str);

// 	// ft_memset(NULL, 'a', 5);
// 	// memset(NULL, 'a', 5);

// 	return (0);
// }