/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 20:51:16 by idel-poz          #+#    #+#             */
/*   Updated: 2024/09/29 17:58:49 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	apply_ra_rb(t_stack_node **a, t_stack_node **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->value != c && find_place_b(*b, c) > 0)
			rr(a, b, 0);
		while ((*a)->value != c)
			ra(a, 0);
		while (find_place_b(*b, c) > 0)
			rb(b, 0);
		pb(a, b, 0);
	}
	else
	{
		while ((*b)->value != c && find_place_a(*a, c) > 0)
			rr(a, b, 0);
		while ((*b)->value != c)
			rb(b, 0);
		while (find_place_a(*a, c) > 0)
			ra(a, 0);
		pa(a, b, 0);
	}
	return (-1);
}

int	apply_rra_rrb(t_stack_node **a, t_stack_node **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->value != c && find_place_b(*b, c) > 0)
			rrr(a, b, 0);
		while ((*a)->value != c)
			rra(a, 0);
		while (find_place_b(*b, c) > 0)
			rrb(b, 0);
		pb(a, b, 0);
	}
	else
	{
		while ((*b)->value != c && find_place_a(*a, c) > 0)
			rrr(a, b, 0);
		while ((*b)->value != c)
			rrb(b, 0);
		while (find_place_a(*a, c) > 0)
			rra(a, 0);
		pa(a, b, 0);
	}
	return (-1);
}

int	apply_rra_rb(t_stack_node **a, t_stack_node **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->value != c)
			rra(a, 0);
		while (find_place_b(*b, c) > 0)
			rb(b, 0);
		pb(a, b, 0);
	}
	else
	{
		while (find_place_a(*a, c) > 0)
			rra(a, 0);
		while ((*b)->value != c)
			rb(b, 0);
		pa(a, b, 0);
	}
	return (-1);
}

int	apply_ra_rrb(t_stack_node **a, t_stack_node **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->value != c)
			ra(a, 0);
		while (find_place_b(*b, c) > 0)
			rrb(b, 0);
		pb(a, b, 0);
	}
	else
	{
		while (find_place_a(*a, c) > 0)
			ra(a, 0);
		while ((*b)->value != c)
			rrb(b, 0);
		pa(a, b, 0);
	}
	return (-1);
}
