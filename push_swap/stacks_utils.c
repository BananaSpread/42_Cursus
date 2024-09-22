/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:06:42 by idel-poz          #+#    #+#             */
/*   Updated: 2024/09/22 14:45:56 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int is_valid_number(char *str)
{
	while (*str == ' ')
		str++;
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
		if (!ft_isdigit(*str++))
			return (0);
	return (1);
}

static int	is_within_int_range(char *str)
{
	long	n;
	int		sign;

	n = 0;
	sign = 1;
	while (*str == ' ')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		n = n * 10 + (*str - '0');
		if ((sign == 1 && n > INT_MAX) || (sign == -1 && -n < INT_MIN))
			return (0);
		str++;
	}
	return (1);
}

static int	has_duplicates(int *n_list, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (n_list[i] == n_list[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int *parse_arguments(int argc, char *argv[])
{
	int *n_list;
	int i;

	n_list = malloc(sizeof(int) * argc);
	if (!n_list)
		return (NULL);

	i = 1;
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
			free_and_error(n_list);
		n_list[i - 1] = ft_atoi(argv[i]);
		if (!is_within_int_range(argv[i]))
			free_and_error(n_list);
		i++;
	}
	n_list[i - 1] = '\0';
	if (has_duplicates(n_list, argc - 1))
		free_and_error(n_list);
	return n_list;
}
