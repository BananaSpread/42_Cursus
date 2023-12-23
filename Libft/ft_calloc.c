/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:37:05 by idel-poz          #+#    #+#             */
/*   Updated: 2023/12/23 16:48:24 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	int		*v;

	i = 0;
	v = malloc(count * size);
	while (i < count)
		v[i++] = 0;
	return (v);
}
