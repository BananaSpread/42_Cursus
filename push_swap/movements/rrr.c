/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 19:42:58 by idel-poz          #+#    #+#             */
/*   Updated: 2024/09/29 18:06:26 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_rrr_sub(t_stack_node **b, int j)
{
	t_stack_node	*tmp;
	int				i;

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
		ft_print_str("rrr\n");
}

void	rrr(t_stack_node **a, t_stack_node **b, int j)
{
	t_stack_node	*tmp;
	int				i;

	if (!*a || !((*a)->next) || !*b || !((*b)->next))
		return ;
	i = 0;
	tmp = *a;
	while ((*a)->next)
	{
		i++;
		*a = (*a)->next;
	}
	(*a)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	ft_rrr_sub(b, j);
}
