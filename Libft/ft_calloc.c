/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:37:05 by idel-poz          #+#    #+#             */
/*   Updated: 2024/01/20 19:06:26 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*v;

	i = 0;
	v = malloc(count * size);
	if (!v)
		return (NULL);
	while (i < count)
		((char *)v)[i++] = 0;
	return (v);
}
