/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:37:05 by idel-poz          #+#    #+#             */
/*   Updated: 2024/02/17 16:08:45 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// Assigns a matrix in memory with count number of elements of size size
// in bytes and initializes all elements with 0.
void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*v;

	v = malloc(count * size);
	if (!v)
		return (NULL);
	i = 0;
	while (i < (count * size))
		((char *) v)[i++] = 0;
	return (v);
}

// #include "libft.h"
// #include <stdio.h>
// #include <string.h>

// int main(void)
// {
// 	int		size = 8539;
// 	void	*d1 = ft_calloc(size, sizeof(int));
// 	void	*d2 = calloc(size, sizeof(int));
// 	printf("%p\n", d1);
// 	printf("%p\n", d2);
// 	printf("Compare: %d\n", memcmp(d1, d2, size * sizeof(int)));
// 	free(d1);
// 	free(d2);
// 	return (0);
// }