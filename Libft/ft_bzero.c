/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:14:30 by idel-poz          #+#    #+#             */
/*   Updated: 2024/01/21 15:32:21 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Fills in with zeroes the first n bytes of memory starting at the location
// pointed to by s.
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
