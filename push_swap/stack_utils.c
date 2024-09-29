/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 20:34:29 by idel-poz          #+#    #+#             */
/*   Updated: 2024/09/29 18:01:33 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_value(t_stack_node *stack)
{
	int		i;

	i = stack->value;
	while (stack)
	{
		if (stack->value < i)
			i = stack->value;
		stack = stack->next;
	}
	return (i);
}

int	get_max_value(t_stack_node *stack)
{
	int		i;

	i = stack->value;
	while (stack)
	{
		if (stack->value > i)
			i = stack->value;
		stack = stack->next;
	}
	return (i);
}

int	get_stack_size(t_stack_node *stack)
{
	size_t	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

int	check_if_sorted(t_stack_node *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
