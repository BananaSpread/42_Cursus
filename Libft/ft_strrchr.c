/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:55:06 by idel-poz          #+#    #+#             */
/*   Updated: 2024/01/14 20:30:41 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*v;

	i = 0;
	v = NULL;
	while (s[i])
		if (s[i] == c)
			v = (char *)&s[i];
	return (v);
}
