/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:51:15 by idel-poz          #+#    #+#             */
/*   Updated: 2024/01/27 19:28:10 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

// Finds the char c into the string s and returns a
// pointer to the memori block position
char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
		if (s[i++] == c)
			return ((char *) &s[i - 1]);
	if (s[i] == c)
		return ((char *) &s[i]);
	return (NULL);
}
