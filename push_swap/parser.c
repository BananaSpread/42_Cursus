/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:06:42 by idel-poz          #+#    #+#             */
/*   Updated: 2024/09/29 18:03:19 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_number(char *str)
{
	while (*str == ' ')
		str++;
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

static long	ft_atol(const char *str)
{
	long	v;
	int		m;

	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (!ft_isdigit(*str) && *str != '+' && *str != '-')
		return (0);
	v = 0;
	m = 1;
	if (*str == '-')
	{
		m = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (ft_isdigit(*str))
			v = (v * 10) + (*str - '0');
		else
			break ;
		str++;
	}
	return (v * m);
}

static void	append_stack_node(t_stack_node **stack, int value)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (stack == NULL)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (node == NULL)
		return ;
	node->next = NULL;
	node->value = value;
	if (*stack == NULL)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	parse_arguments(t_stack_node **stack_a, char *argv[], int i)
{
	long	value;

	while (argv[i])
	{
		if (!is_valid_number(argv[i]))
		{
			free_stack(stack_a);
			return ;
		}
		value = ft_atol(argv[i]);
		if (value > INT_MAX || value < INT_MIN)
		{
			free_stack(stack_a);
			return ;
		}
		append_stack_node(stack_a, (int)value);
		++i;
	}
}

void	parse_grouped_arguments(t_stack_node **stack_a, char *args)
{
	char			**values;
	int				len;

	if (!args)
		return ;
	values = ft_split(args, ' ');
	if (!values)
		return ;
	len = 0;
	while (values[len])
		len++;
	parse_arguments(stack_a, values, 0);
	free_argv(values);
}
