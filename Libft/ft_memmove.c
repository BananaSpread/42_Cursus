/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:15:30 by idel-poz          #+#    #+#             */
/*   Updated: 2023/12/11 17:49:27 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	void	*aux;

	i = 0;
	aux = [len];
	while (i < len)
	{
		aux[i] = src[i];
		i++;
	}
	i = 0;
	while (aux[i])
	{
		dst[i] = aux[i];
		i++;
	}
	return (dst);
}
