/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 14:19:29 by idel-poz          #+#    #+#             */
/*   Updated: 2024/09/29 18:05:43 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_b_untill_3(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*tmp;
	int				i;

	while (get_stack_size(*stack_a) > 3 && !check_if_sorted(*stack_a))
	{
		tmp = *stack_a;
		i = rotate_type_ab(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == check_case_ra_rb(*stack_a, *stack_b, tmp->value))
				i = apply_ra_rb(stack_a, stack_b, tmp->value, 'a');
			else if (i == check_case_rra_rrb(*stack_a, *stack_b, tmp->value))
				i = apply_rra_rrb(stack_a, stack_b, tmp->value, 'a');
			else if (i == check_case_ra_rrb(*stack_a, *stack_b, tmp->value))
				i = apply_ra_rrb(stack_a, stack_b, tmp->value, 'a');
			else if (i == check_case_rra_rb(*stack_a, *stack_b, tmp->value))
				i = apply_rra_rb(stack_a, stack_b, tmp->value, 'a');
			else
				tmp = tmp->next;
		}
	}
}

static t_stack_node	*sort_b(t_stack_node **stack_a)
{
	t_stack_node	*stack_b;

	stack_b = NULL;
	if (get_stack_size(*stack_a) > 3 && !check_if_sorted(*stack_a))
		pb(stack_a, &stack_b, 0);
	if (get_stack_size(*stack_a) > 3 && !check_if_sorted(*stack_a))
		pb(stack_a, &stack_b, 0);
	if (get_stack_size(*stack_a) > 3 && !check_if_sorted(*stack_a))
		sort_b_untill_3(stack_a, &stack_b);
	if (!check_if_sorted(*stack_a))
		tiny_sort(stack_a);
	return (stack_b);
}

static t_stack_node	**sort_a(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*tmp;
	int				i;

	while (*stack_b)
	{
		tmp = *stack_b;
		i = rotate_type_ba(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == check_case_ra_rb_a(*stack_a, *stack_b, tmp->value))
				i = apply_ra_rb(stack_a, stack_b, tmp->value, 'b');
			else if (i == check_case_ra_rrb_a(*stack_a, *stack_b, tmp->value))
				i = apply_ra_rrb(stack_a, stack_b, tmp->value, 'b');
			else if (i == check_case_rra_rrb_a(*stack_a, *stack_b, tmp->value))
				i = apply_rra_rrb(stack_a, stack_b, tmp->value, 'b');
			else if (i == check_case_rra_rb_a(*stack_a, *stack_b, tmp->value))
				i = apply_rra_rb(stack_a, stack_b, tmp->value, 'b');
			else
				tmp = tmp->next;
		}
	}
	return (stack_a);
}

void	sort_stack(t_stack_node **stack_a)
{
	t_stack_node	*stack_b;
	int				i;

	stack_b = NULL;
	if (get_stack_size(*stack_a) == 2)
	{
		sa(stack_a, 0);
		return ;
	}
	stack_b = sort_b(stack_a);
	stack_a = sort_a(stack_a, &stack_b);
	i = find_index(*stack_a, get_min_value(*stack_a));
	if (i < get_stack_size(*stack_a) - i)
	{
		while ((*stack_a)->value != get_min_value(*stack_a))
			ra(stack_a, 0);
	}
	else
	{
		while ((*stack_a)->value != get_min_value(*stack_a))
			rra(stack_a, 0);
	}
}

void	tiny_sort(t_stack_node **stack_a)
{
	if (get_min_value(*stack_a) == (*stack_a)->value)
	{
		rra(stack_a, 0);
		sa(stack_a, 0);
	}
	else if (get_max_value(*stack_a) == (*stack_a)->value)
	{
		ra(stack_a, 0);
		if (!check_if_sorted(*stack_a))
			sa(stack_a, 0);
	}
	else
	{
		if (find_index(*stack_a, get_max_value(*stack_a)) == 1)
			rra(stack_a, 0);
		else
			sa(stack_a, 0);
	}
}
