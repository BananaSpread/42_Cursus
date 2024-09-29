/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 19:42:00 by idel-poz          #+#    #+#             */
/*   Updated: 2024/09/29 17:53:59 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ss(t_stack_node **a, t_stack_node **b, int j)
{
	t_stack_node	*tmp;

	if (!*a || !((*a)->next) || !*b || !((*b)->next))
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
	if (j == 0)
		ft_print_str("ss\n");
}
