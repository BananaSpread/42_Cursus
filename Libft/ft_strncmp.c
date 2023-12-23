/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:01:01 by idel-poz          #+#    #+#             */
/*   Updated: 2023/12/16 19:25:51 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	char	c1;
	char	c2;

	i = 0;
	while (i <= n)
	{
		c1 = s1[i];
		c2 = s2[i];
		i++;
		if (!c1 || !c2)
			continue ;
		if (c1 > c2)
			return (-1);
		if (c1 < c2)
			return (1);
	}
	return (0);
}
