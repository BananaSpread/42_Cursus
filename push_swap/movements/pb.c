/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 19:43:45 by idel-poz          #+#    #+#             */
/*   Updated: 2024/09/29 17:53:30 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pb(t_stack_node **stack_a, t_stack_node **stack_b, int j)
{
	t_stack_node	*tmp;

	if (!*stack_a)
		return ;
	tmp = *stack_b;
	*stack_b = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_b)->next = tmp;
	if (j == 0)
		ft_print_str("pb\n");
}
