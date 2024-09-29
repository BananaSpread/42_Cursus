/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 19:43:59 by idel-poz          #+#    #+#             */
/*   Updated: 2024/09/29 18:06:58 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rrb(t_stack_node **b, int j)
{
	t_stack_node	*tmp;
	int				i;

	if (!*b || !(*b)->next)
		return ;
	i = 0;
	tmp = *b;
	while ((*b)->next)
	{
		i++;
		*b = (*b)->next;
	}
	(*b)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	if (j == 0)
		ft_print_str("rrb\n");
}
