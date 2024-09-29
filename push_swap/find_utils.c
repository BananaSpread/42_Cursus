/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 20:55:02 by idel-poz          #+#    #+#             */
/*   Updated: 2024/09/29 18:04:31 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*find_last_node(t_stack_node *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int	find_index(t_stack_node *stack, int value)
{
	int		i;

	i = 0;
	while (stack->value != value)
	{
		stack = stack->next;
		i++;
	}
	stack->index = 0;
	return (i);
}

int	find_place_b(t_stack_node *stack_b, int value_push)
{
	t_stack_node	*tmp;
	int				i;

	i = 1;
	if (value_push > stack_b->value
		&& value_push < find_last_node(stack_b)->value)
		i = 0;
	else if (value_push > get_max_value(stack_b)
		|| value_push < get_min_value(stack_b))
		i = find_index(stack_b, get_max_value(stack_b));
	else
	{
		tmp = stack_b->next;
		while (stack_b->value < value_push || tmp->value > value_push)
		{
			stack_b = stack_b->next;
			tmp = stack_b->next;
			i++;
		}
	}
	return (i);
}

int	find_place_a(t_stack_node *stack_a, int value_push)
{
	t_stack_node	*tmp;
	int				i;

	i = 1;
	if (value_push < stack_a->value
		&& value_push > find_last_node(stack_a)->value)
		i = 0;
	else if (value_push > get_max_value(stack_a)
		|| value_push < get_min_value(stack_a))
		i = find_index(stack_a, get_min_value(stack_a));
	else
	{
		tmp = stack_a->next;
		while (stack_a->value > value_push || tmp->value < value_push)
		{
			stack_a = stack_a->next;
			tmp = stack_a->next;
			i++;
		}
	}
	return (i);
}
