/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:06:42 by idel-poz          #+#    #+#             */
/*   Updated: 2024/09/22 18:15:55 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_argv(char **argv)
{
	int	i;

	if (!argv)
		return ;
	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;	
	}
	free(argv);
}

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

int *parse_arguments(int size, char *argv[], int i)
{
	int *n_list;

	n_list = malloc(sizeof(int) * size);
	if (!n_list)
		return (NULL);
	ft_printf("size = %d\n", size);
	while (i < size)
	{
		ft_printf("Number to check: %s\n", argv[i]);
		n_list[i - 1] = ft_atoi(argv[i]);
		if (!is_valid_number(argv[i]) || !is_within_int_range(argv[i]))
		{
			free_and_error(n_list);
			return (NULL);
		}
		i++;
	}
	n_list[i - 1] = '\0';
	if (!has_duplicates(n_list, size - 1))
		return n_list;
	free_and_error(n_list);
	return (NULL);
}

int	*parse_grouped_arguments(char *args)
{
	char	**values;
	int		*stack;
	int		len;

	if (!args)
		return (NULL);
	values = ft_split(args, ' ');
	if (!values)
		return (NULL);
	len = 0;
	while (values[len])
		len++;
	stack = parse_arguments(len, values, 0);
	free_argv(values);
	return (stack);
}
