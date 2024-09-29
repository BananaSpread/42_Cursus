/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 20:28:33 by idel-poz          #+#    #+#             */
/*   Updated: 2024/09/29 18:03:02 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_type_ab(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*tmp;
	int				i;

	tmp = a;
	i = check_case_rra_rrb(a, b, a->value);
	while (tmp)
	{
		if (i > check_case_ra_rb(a, b, tmp->value))
			i = check_case_ra_rb(a, b, tmp->value);
		if (i > check_case_rra_rrb(a, b, tmp->value))
			i = check_case_rra_rrb(a, b, tmp->value);
		if (i > check_case_ra_rrb(a, b, tmp->value))
			i = check_case_ra_rrb(a, b, tmp->value);
		if (i > check_case_rra_rb(a, b, tmp->value))
			i = check_case_rra_rb(a, b, tmp->value);
		tmp = tmp->next;
	}
	return (i);
}

int	rotate_type_ba(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*tmp;
	int				i;

	tmp = b;
	i = check_case_rra_rrb_a(a, b, b->value);
	while (tmp)
	{
		if (i > check_case_ra_rb_a(a, b, tmp->value))
			i = check_case_ra_rb_a(a, b, tmp->value);
		if (i > check_case_rra_rrb_a(a, b, tmp->value))
			i = check_case_rra_rrb_a(a, b, tmp->value);
		if (i > check_case_ra_rrb_a(a, b, tmp->value))
			i = check_case_ra_rrb_a(a, b, tmp->value);
		if (i > check_case_rra_rb_a(a, b, tmp->value))
			i = check_case_rra_rb_a(a, b, tmp->value);
		tmp = tmp->next;
	}
	return (i);
}
