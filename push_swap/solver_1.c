/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 20:45:05 by idel-poz          #+#    #+#             */
/*   Updated: 2024/09/29 18:05:59 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_case_ra_rb(t_stack_node *a, t_stack_node *b, int c)
{
	int	i;

	i = find_place_b(b, c);
	if (i < find_index(a, c))
		i = find_index(a, c);
	return (i);
}

int	check_case_rra_rrb(t_stack_node *a, t_stack_node *b, int c)
{
	int	i;

	i = 0;
	if (find_place_b(b, c))
		i = get_stack_size(b) - find_place_b(b, c);
	if ((i < (get_stack_size(a) - find_index(a, c))) && find_index(a, c))
		i = get_stack_size(a) - find_index(a, c);
	return (i);
}

int	check_case_rra_rb(t_stack_node *a, t_stack_node *b, int c)
{
	int	i;

	i = 0;
	if (find_index(a, c))
		i = get_stack_size(a) - find_index(a, c);
	i = find_place_b(b, c) + i;
	return (i);
}

int	check_case_ra_rrb(t_stack_node *a, t_stack_node *b, int c)
{
	int	i;

	i = 0;
	if (find_place_b(b, c))
		i = get_stack_size(b) - find_place_b(b, c);
	i = find_index(a, c) + i;
	return (i);
}
