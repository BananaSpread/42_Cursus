/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 19:41:27 by idel-poz          #+#    #+#             */
/*   Updated: 2024/09/29 17:53:27 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_stack_node **a, t_stack_node **b, int j)
{
	t_stack_node	*tmp;

	if (!*b)
		return ;
	tmp = *a;
	*a = *b;
	*b = (*b)->next;
	(*a)->next = tmp;
	if (j == 0)
		ft_print_str("pa\n");
}
