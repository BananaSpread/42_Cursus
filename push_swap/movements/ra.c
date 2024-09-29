/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 19:41:06 by idel-poz          #+#    #+#             */
/*   Updated: 2024/09/29 18:06:17 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack_node **a, int j)
{
	t_stack_node	*tmp;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	*a = find_last_node(*a);
	(*a)->next = tmp;
	*a = tmp->next;
	tmp->next = NULL;
	if (j == 0)
		ft_print_str("ra\n");
}
