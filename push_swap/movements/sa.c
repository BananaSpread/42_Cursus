/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 19:34:00 by idel-poz          #+#    #+#             */
/*   Updated: 2024/09/29 18:06:44 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack_node **a, int j)
{
	t_stack_node	*tmp;

	if (!*a || !((*a)->next))
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	if (j == 0)
		ft_print_str("sa\n");
}
