/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 19:42:38 by idel-poz          #+#    #+#             */
/*   Updated: 2024/09/29 18:06:35 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rr(t_stack_node **a, t_stack_node **b, int j)
{
	t_stack_node	*tmp;

	if (!*a || !((*a)->next) || !*b || !((*b)->next))
		return ;
	tmp = *a;
	*a = find_last_node(*a);
	(*a)->next = tmp;
	*a = tmp->next;
	tmp->next = NULL;
	tmp = *b;
	*b = find_last_node(*b);
	(*b)->next = tmp;
	*b = tmp->next;
	tmp->next = NULL;
	if (j == 0)
		ft_print_str("rr\n");
}
