/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 12:27:27 by idel-poz          #+#    #+#             */
/*   Updated: 2024/09/29 17:55:46 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	has_duplicates(t_stack_node *stack)
{
	t_stack_node	*tmp;

	if (!stack->next)
		return (0);
	while (stack)
	{
		tmp = stack->next;
		while (tmp)
		{
			if (stack->value == tmp->value)
				return (1);
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (0);
}

static t_stack_node	*init_stack(int argc, char *argv[])
{
	t_stack_node	*stack_a;

	stack_a = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		exit(EXIT_FAILURE);
	else if (argc == 2)
		parse_grouped_arguments(&stack_a, argv[1]);
	else
		parse_arguments(&stack_a, argv, 1);
	return (stack_a);
}

int	main(int argc, char *argv[])
{
	t_stack_node	*stack_a;

	stack_a = init_stack(argc, argv);
	if (!stack_a || has_duplicates(stack_a))
	{
		free_stack(&stack_a);
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (!check_if_sorted(stack_a))
		sort_stack(&stack_a);
	free_stack(&stack_a);
	return (0);
}
