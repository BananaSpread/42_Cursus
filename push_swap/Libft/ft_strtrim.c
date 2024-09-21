/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:33:53 by idel-poz          #+#    #+#             */
/*   Updated: 2024/01/28 17:26:03 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Removes specified set chars from the start and end of
// the string s1.
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*trim;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	len = ft_strlen(s1);
	while (len && ft_strchr(set, s1[len - 1]))
		len--;
	trim = malloc(sizeof(char) * (len + 1));
	if (!trim)
		return (NULL);
	ft_memcpy(trim, s1, len);
	trim[len] = '\0';
	return (trim);
}
