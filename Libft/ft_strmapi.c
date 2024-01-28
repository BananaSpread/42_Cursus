/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 14:48:17 by idel-poz          #+#    #+#             */
/*   Updated: 2024/01/28 13:48:15 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Applies a function to every char of the string s creating
// a new string with the results and returns a pointer to that string.
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*v;

	i = 0;
	v = malloc((sizeof(char) * ft_strlen(s)) + 1);
	if (!v)
		return (NULL);
	while (s[i])
	{
		v[i] = f(i, s[i]);
		i++;
	}
	v[i] = '\0';
	return (v);
}
