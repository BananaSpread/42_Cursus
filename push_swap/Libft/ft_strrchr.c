/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:55:06 by idel-poz          #+#    #+#             */
/*   Updated: 2024/01/28 17:26:29 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Search the last c char in the string s.
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char) c)
			return ((char *) &s[i]);
		i--;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>
// int	main()
// {
// 	char *str = "teste";
// 	int c 	  = 0;
// 	printf("\t%s\n", ft_strrchr(str, c));
// 	printf("\t%s\n", strrchr(str, c));
// 	return (0);
// }