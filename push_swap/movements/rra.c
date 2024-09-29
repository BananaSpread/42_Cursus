/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 19:41:41 by idel-poz          #+#    #+#             */
/*   Updated: 2024/09/29 18:07:20 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_stack_node **a, int j)
{
	t_stack_node	*tmp;
	int				i;

	if (!*a || !(*a)->next)
		return ;
	i = 0;
	tmp = *a;
	while ((*a)->next)
	{
		*a = (*a)->next;
		i++;
	}
	(*a)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	if (j == 0)
		ft_print_str("rra\n");
}
