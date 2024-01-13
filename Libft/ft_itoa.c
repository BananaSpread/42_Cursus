/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 14:47:14 by idel-poz          #+#    #+#             */
/*   Updated: 2024/01/13 14:49:35 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_itoa(int n)
{
	char	*v;
	size_t	i;
	int		aux;

	v = malloc(sizeof(char) * 12);
	i = 0;
	aux = n;
	while (aux > 0)
	{
		v[i] = aux % 10;
		aux /= 10;
		i++;
	}
	if (n < 0)
		v[i++] = '-';
	v[i++] = '\0';
	return (ft_reverse(v, i));
}

char	static	*ft_reverse(char s*, int size)
{
	char	c;
	size_t	i;

	i = 0;
	while (i < size / 2)
	{
		c = s[i];
		s[i] = s[size - i - 1];
		s[size - i - 1] = c;
		i++;
	}
	return (s);
}
