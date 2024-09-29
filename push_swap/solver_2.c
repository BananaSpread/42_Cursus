/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 20:42:49 by idel-poz          #+#    #+#             */
/*   Updated: 2024/09/29 18:04:50 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_case_ra_rb_a(t_stack_node *a, t_stack_node *b, int c)
{
	int	i;

	i = find_place_a(a, c);
	if (i < find_index(b, c))
		i = find_index(b, c);
	return (i);
}

int	check_case_rra_rrb_a(t_stack_node *a, t_stack_node *b, int c)
{
	int	i;

	i = 0;
	if (find_place_a(a, c))
		i = get_stack_size(a) - find_place_a(a, c);
	if ((i < (get_stack_size(b) - find_index(b, c))) && find_index(b, c))
		i = get_stack_size(b) - find_index(b, c);
	return (i);
}

int	check_case_ra_rrb_a(t_stack_node *a, t_stack_node *b, int c)
{
	int	i;

	i = 0;
	if (find_index(b, c))
		i = get_stack_size(b) - find_index(b, c);
	i = find_place_a(a, c) + i;
	return (i);
}

int	check_case_rra_rb_a(t_stack_node *a, t_stack_node *b, int c)
{
	int	i;

	i = 0;
	if (find_place_a(a, c))
		i = get_stack_size(a) - find_place_a(a, c);
	i = find_index(b, c) + i;
	return (i);
}
