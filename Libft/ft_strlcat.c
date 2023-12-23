/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:16:25 by idel-poz          #+#    #+#             */
/*   Updated: 2023/12/16 18:41:36 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	i;
	char	*aux;

	i = 0;
	while (src[i])
	{
		aux[i] = src[i];
		i++;
	}
	i = 0;
	while (dst[i])
		i++;
	while (aux[i])
	{
		dst[i] = aux[i];
		i++;
	}
	if (i > 0)
		dst[i] = '\0';
	return (i);
}
