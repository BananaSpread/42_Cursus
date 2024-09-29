/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 19:36:47 by idel-poz          #+#    #+#             */
/*   Updated: 2024/09/29 17:53:56 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sb(t_stack_node **b, int j)
{
	t_stack_node	*tmp;

	if (!*b || !((*b)->next))
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
	if (j == 0)
		ft_print_str("sa\n");
}
