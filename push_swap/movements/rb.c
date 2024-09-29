/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 19:42:19 by idel-poz          #+#    #+#             */
/*   Updated: 2024/09/29 17:53:37 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rb(t_stack_node **b, int j)
{
	t_stack_node	*tmp;

	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	*b = find_last_node(*b);
	(*b)->next = tmp;
	*b = tmp->next;
	tmp->next = NULL;
	if (j == 0)
		ft_print_str("rb\n");
}
